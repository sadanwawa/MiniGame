
#include <iostream>
#include <stdexcept>
#include "DelegateCommandManager.h"
#include "Exception.h"

// singleton instance pointer
template<> DelegateCommandManager* Singleton<DelegateCommandManager>::msSingleton	= NULL;


/*************************************************************************
 Constructor
 *************************************************************************/
DelegateCommandManager::DelegateCommandManager(void)
{
}
/*************************************************************************
 Destructor
 *************************************************************************/
DelegateCommandManager::~DelegateCommandManager(void)
{
    mCommandMap.clear();
}


void DelegateCommandManager::registerCommand(std::string const& command_type, ICommand* command, void const* obj_ptr/*= NULL*/)
{

    CommandMap::iterator result = mCommandMap.find(command_type);
    CommandMap::value_type::second_type cmdlist = NULL;

    if (result == mCommandMap.end() )
    {
        cmdlist = new CommandList();
        cmdlist->push_back(std::make_pair(command, obj_ptr));

        mCommandMap[command_type] =  cmdlist;
    }
    else
    {
        cmdlist = result->second;
        cmdlist->push_back(std::make_pair(command, obj_ptr));
    }
 
    NoticeMap::iterator it;

    for(it=mNoticeMap.begin(); it!=mNoticeMap.end();)
    {
        if(it->first == command_type){
            NoticeMap::value_type::second_type pair = it->second;
            executeCommand(pair.first, pair.second);
            
            DelegateCommandManager::NoticeMap::iterator tmp = it;            
            ++tmp;
            mNoticeMap.erase(it);
            it = tmp;
        }
        else {
            ++it;
        }
    }
}

void DelegateCommandManager::executeCommand(const INotification& notification, void const* obj_ptr)
{
    CommandMap::value_type::second_type commandList = NULL;
    
    // Retrieve the named mediator
    CommandMap::iterator result = mCommandMap.find(notification.getType());
    
    if (result == mCommandMap.end() ){
       
        NoticeMap::iterator notice = mNoticeMap.find(notification.getType());
        if (notice == mNoticeMap.end() ){
            mNoticeMap[notification.getType()] = std::make_pair(notification, obj_ptr);
        }   
        
        return ;
    }
    
    // get mediator
    commandList = result->second;
    
    // execute Commands
    if(!(commandList->empty()))
    {
        DelegateCommandManager::CommandList::iterator it = commandList->begin();
        DelegateCommandManager::CommandList::iterator itEnd = commandList->end();
        
        for(; it!= itEnd;)
        {
            if((*it).first)
            {
                if(obj_ptr){
                    if((*it).second == obj_ptr)
                        ((*it).first)->execute((*it).second, notification);
                }
                else {
                    ((*it).first)->execute((*it).second, notification);
                }
            }
            it++;
            
        }
    }
}

void DelegateCommandManager::removeAllCommands()
{
    mCommandMap.clear();
    mNoticeMap.clear();
}

DelegateCommandManager::CommandList* DelegateCommandManager::removeCommandList(std::string const& command_type)
{
    CommandMap::value_type::second_type command = NULL;
    
    do
    {
        // Retrieve the named mediator
        CommandMap::iterator result = mCommandMap.find(command_type);
            
        if (result == mCommandMap.end() )
            break;
        
        // get mediator
        command = result->second;
        // remove the mediator from the map
        mCommandMap.erase(result);
        
    }while (false);
    
    return command;
}

void DelegateCommandManager::removeCommand(void const* obj_ptr)
{
    CommandMap::iterator mapit;
    CommandMap::value_type::second_type commandList = NULL;
    CommandList::iterator it;

    for(mapit=mCommandMap.begin(); mapit != mCommandMap.end();)
    {
        commandList = mapit->second;
        
        if(!commandList->empty()){

            
            for(it=commandList->begin(); it!=commandList->end();)
            {     
                if((*it).second == obj_ptr){                    

                    mCommandITVector.push_back(it);
                }             
                ++it;
            }
        }
         
        ++mapit;
    }    
}

void DelegateCommandManager::DelayRemovedCommands()
{
    int sum = mCommandITVector.size();
    CommandMap::iterator mapit;
    CommandMap::value_type::second_type commandList = NULL;
    CommandList::iterator it;
    
    for(int i=0; i<sum;++i)
    {
        CommandList::iterator removedit = mCommandITVector[i];
        
        for(mapit=mCommandMap.begin(); mapit != mCommandMap.end();)
        {
            commandList = mapit->second;
            
            if(!commandList->empty()){
                
                for(it=commandList->begin(); it!=commandList->end();)
                {     
                    if(it == removedit){
                        DelegateCommandManager::CommandList::iterator tmp = it;
                        ++tmp;
                        commandList->erase(it);
                        it = tmp;
                    }
                    else {
                        ++it;
                    }
                    
                }
            }
            if (commandList->size() == 0) 
            {
                DelegateCommandManager::CommandMap::iterator tmpMapit = mapit;
                ++tmpMapit;
                mCommandMap.erase(mapit);
                mapit = tmpMapit;
            }
            else {
                ++mapit;
            }
            
        }   
        
    }
    mCommandITVector.clear();
}


DelegateCommandManager::CommandList const& DelegateCommandManager::retrieveCommandList(std::string const& command_name) const
{
   
    CommandMap::const_iterator result = mCommandMap.find(command_name);
    if (result == mCommandMap.end())
        throwException<std::runtime_error>("Cannot find any command with command name: [%s].", command_name.c_str());
    
    return *result->second;
}
