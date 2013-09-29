

#ifndef minGameTest_Command_h
#define minGameTest_Command_h

#include "INotification.h"

class ICommand
{
    public:
		virtual ~ICommand(){}
        virtual void execute(void const* obj_ptr, INotification const& notification)=0;
    
};

template <typename T>
class DelegateCommand: public ICommand
{
private:
    typedef void (T::*HandlerPtr)(INotification const& notification);
    const HandlerPtr handler;
    
public:
    void execute(void const* obj_ptr, INotification const& notification)
    {
        if( !obj_ptr )
            return ;
        
        (((T*)obj_ptr)->*handler)(notification);
    }
    
    DelegateCommand(const HandlerPtr ptr):handler(ptr) {}  // 此处为新添加代码
    
};

typedef void (*StaticHandlerPtr)(INotification const& notification);

template <typename ObjectType>
class MultiDelegateCommand: public ICommand
{    
private:
    typedef void (ObjectType::*HandlerPtr)(INotification const& notification);
    const HandlerPtr handler;
    const StaticHandlerPtr sthandler;

public:

    void execute(void const* obj_ptr, INotification const& notification)
    {
        if( !obj_ptr ){
            sthandler(notification);
        }
        else {
            (((ObjectType*)obj_ptr)->*handler)(notification);
        }        
    }    
    
    MultiDelegateCommand(const HandlerPtr ptr,const StaticHandlerPtr stptr):handler(ptr),sthandler(stptr){}  // 此处为新添加代码

};

#endif
