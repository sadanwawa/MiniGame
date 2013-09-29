
#ifndef minGameTest_INotification_h
#define minGameTest_INotification_h

#include <string>
using namespace std;

struct INotification
{
    /**
     * Get the name of the <code>INotification</code> instance.
     * No setter, should be set by constructor only
     */
    virtual std::string const& getName(void) const;
    
    /**
     * Set the body of the <code>INotification</code> instance
     */
    virtual void setBody(void const* body){};
    
    /**
     * Get the body of the <code>INotification</code> instance
     */
    virtual void const* getBody(void) const{return NULL;};
    
    /**
     * Set the type of the <code>INotification</code> instance
     */
    virtual void setType(std::string const& type){};
    
    /**
     * Get the type of the <code>INotification</code> instance
     */
    virtual std::string const& getType(void) const;
    
    /**
     * Get the string representation of the <code>INotification</code> instance
     */
    virtual std::string toString(void) const;
    
    /**
     * Get the string representation of the <code>INotification</code> instance
     */
    virtual void toString(std::string& arg) const{};


    /**
     * Virtual destructor.
     */
    virtual ~INotification(void){};
};
#endif
