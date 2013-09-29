
#ifndef minGameTest_DelegateCommandManager_h
#define minGameTest_DelegateCommandManager_h

#include "../core/Singleton.h"
#include "Command.h"
#include "Notification.h"

#include <map>
#include <vector>
#include <list>

class DelegateCommandManager : public Singleton<DelegateCommandManager>
{
protected:
    typedef std::list< std::pair< ICommand*, void const* > > CommandList;
    typedef std::map<std::string, CommandList*> CommandMap;
    typedef std::vector<CommandList::iterator> CommandITVector;
    typedef std::pair< INotification, void const* > NoticePair;

    typedef std::map<std::string, NoticePair > NoticeMap;

    NoticeMap mNoticeMap;
    CommandMap mCommandMap;
    CommandITVector mCommandITVector;
protected:
    /**
     * Define iterator converter for getting Command name only.
     */
    struct IteratorConverter
    : public std::unary_function<CommandMap::const_iterator, CommandMap::key_type>
    {
        /**
         * Converting operator.
         *
         * @param iterator the iterator of internal container.
         * @return the name of Command inside iterator.
         */
        CommandMap::key_type const& operator()(CommandMap::const_iterator const& iterator) const{
            return iterator->first;
        }
    };
    /**
     * Define iterator range of internal container.
     */
    struct IteratorRange {
        /**
         * Get begin point.
         *
         * @return the begin of iterator.
         */
        CommandMap::const_iterator begin(CommandMap const* const& iterator) const{
            return iterator->begin();
        }
        /*
         * Get end point.
         *
         * @return the end of iterator.
         */
        CommandMap::const_iterator end(CommandMap const* const& iterator) const{
            return iterator->end();
        }
    };
    
public:
    /*************************************************************************
     Construction and Destruction
     *************************************************************************/
	/*!
     \brief
     Constructs a new DelegateCommandManager.
     */
	DelegateCommandManager(void);    
    
	/*!
     \brief
     Destructor for DelegateCommandManager
     */
	~DelegateCommandManager(void);
    
    /**
     * If an <code>ICommand</code> has previously been registered
     * to handle a the given <code>INotification</code>, then it is executed.
     *
     * @param notification an <code>INotification</code>
     */
   // virtual void executeCommand(INotification const& notification);
    
    /**
     * Register a particular <code>ICommand</code> class as the handler
     * for a particular <code>INotification</code>.
     *
     * <P>
     * If an <code>ICommand</code> has already been registered to
     * handle <code>INotification</code>s with this name, it is no longer
     * used, the new <code>ICommand</code> is used instead.</P>
     *
     * The Observer for the new ICommand is only created if this the
     * first time an ICommand has been regisered for this Notification name.
     *
     * @param command_type the name of the <code>INotification</code>
     * @param command the command of the <code>ICommand</code>
     */
    void registerCommand(std::string const& command_type, ICommand* command, void const* obj_ptr = NULL);
    
    /**
     * execute Commands for a given Notification
     *
     * @param notice
     * @return void.
     */
    void executeCommand(const INotification& notification, void const* obj_ptr = NULL);
    
    /**
     * Check if a Command is registered for a given Notification
     *
     * @param command_type
     * @return whether a Command is currently registered for the given <code>command_type</code>.
     */
    bool hasCommand(std::string const& command_type) const{
        return mCommandMap.find(command_type) != mCommandMap.end();
    }
    
    /**
     * Retrieve an <code>ICommand</code> instance from the Controller.
     *
     * @param command_type the notification of the <code>INotification</code>
     * @return the <code>ICommand</code> instance previously registered with the given <code>notification</code>.
     */
    CommandList const& retrieveCommandList(std::string const& command_type) const;
    
    /**
     * Retrieve an <code>ICommand</code> instance from the Controller.
     *
     * @param command_type the name of the <code>INotification</code>
     * @return the <code>ICommand</code> instance previously registered with the given <code>notification</code>.
     */
    CommandList& retrieveCommandList(std::string const& command_type){
        return const_cast<CommandList&>(static_cast<DelegateCommandManager const&>(*this).retrieveCommandList(command_type));
    }
    
    /**
     * Remove a previously registered <code>ICommand</code> to <code>INotification</code> mapping.
     *
     * @param command_type the name of the <code>INotification</code> to remove the <code>ICommand</code> mapping for
     * @return the <code>ICommand</code> that was removed from the <code>Controller</code>
     */
    CommandList* removeCommandList(std::string const& command_type);
      
    /**
     * Remove command mapping.
     *
     * @return void
     */
    void removeAllCommands();
    
    /**
     * Remove a previously registered <code>ICommand</code> to <code>INotification</code> mapping.
     *
     * @param obj_ptr the ptr of  <code>ICommand</code> mapping for
     * @return the <code>ICommand</code> that was removed from the <code>Controller</code>
     */
    void removeCommand(void const* obj_ptr);
    
    
    void DelayRemovedCommands();
        
};

#define CC_REGISTER_OBJ_COMMAND(COMMAND_TYPE, CLASS, OBJ_PTR, METHOD)\
    DelegateCommandManager::Instance()->registerCommand(COMMAND_TYPE, new MultiDelegateCommand<CLASS>(&CLASS::METHOD,NULL), OBJ_PTR);


#define CC_REGISTER_GLOBAL_COMMAND(COMMAND_TYPE, CLASS, METHOD)\
    DelegateCommandManager::Instance()->registerCommand(COMMAND_TYPE, new MultiDelegateCommand<CLASS>(NULL,&CLASS::METHOD), NULL);

#define CC_EXECUTE_COMMAND(NOTIFICATION)\
    DelegateCommandManager::Instance()->executeCommand(NOTIFICATION);

#define CC_EXECUTE_COMMAND_SINGLE(NOTIFICATION, OBJ_PTR)\
    DelegateCommandManager::Instance()->executeCommand(NOTIFICATION, OBJ_PTR);

#define CC_REMOVE_COMMAND(OBJ_PTR)\
    DelegateCommandManager::Instance()->removeCommand(OBJ_PTR);

#define CC_REMOVE_COMMANDLIST(COMMAND_TYPE)\
    DelegateCommandManager::Instance()->removeCommandList(COMMAND_TYPE);

#define CC_REMOVE_ALLCOMMAND()\
    DelegateCommandManager::Instance()->removeAllCommands();

#endif
