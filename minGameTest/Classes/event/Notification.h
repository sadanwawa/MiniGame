
#ifndef minGameTest_Notification_h
#define minGameTest_Notification_h

#include "INotification.h"
#include <typeinfo>

class Notification : public virtual INotification
{
public:
    /**
     * Copy constructor.
     */
    explicit Notification(Notification const& arg);
    
    /**
     * Constructor.
     *
     * @param name name of the <code>Notification</code> instance. (required)
     * @param body the <code>Notification</code> body. (optional)
     * @param type the type of the <code>Notification</code> (optional)
     */
    Notification(std::string const& type, void const* body = NULL, std::string const& name = "");
    
    /**
     * Get the name of the <code>Notification</code> instance.
     *
     * @return the name of the <code>Notification</code> instance.
     */
    virtual std::string const& getName(void) const{
        return mName;
    }
    
    /**
     * Set the body of the <code>Notification</code> instance.
     */
    virtual void setBody(void const* body){
        mBody = body;
    }
    
    /**
     * Get the body of the <code>Notification</code> instance.
     *
     * @return the body object.
     */
    virtual void const* getBody(void) const{
        return mBody;
    }
    
    /**
     * Set the type of the <code>Notification</code> instance.
     */
    virtual void setType(std::string const& type){
        mType = type;
    }
    
    /**
     * Get the type of the <code>Notification</code> instance.
     *
     * @return the type
     */
    virtual std::string const& getType(void) const{
        return mType;
    }

    
    /**
     * Get the string representation of the <code>Notification</code> instance.
     *
     * @return the string representation of the <code>Notification</code> instance.
     */
    virtual std::string toString(void) const{
        std::string msg;
        toString(msg);
        return msg;
    }
    
    /**
     * Get the string representation of the <code>INotification</code> instance.
     */
    virtual void toString(std::string& arg) const{
        arg = "Notification Name: ";
        arg += getName();
        arg += "\nBody: ";
        arg += typeid(mBody).name();
        arg += "\nType: ";
        arg += mType;
    }

    
    /**
     * Copy operator.
     */
    Notification& operator=(Notification const& arg);
    
    /**
     * Virtual destructor.
     */
    virtual ~Notification(void){};
private:
    // the name of the notification instance
    std::string mName;
    // the body of the notification instance
    void const* mBody;
    // the type of the notification instance
    std::string mType;
};

#endif
