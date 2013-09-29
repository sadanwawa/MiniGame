
#include <iostream>

#include "Notification.h"

Notification::Notification(std::string const& type,
                           void const* body,
                           std::string const& name)
: INotification()
, mType(type)
, mName(name)
, mBody(body)
{ }

Notification::Notification(Notification const& arg)
: INotification()
, mType(arg.mType)
, mBody(arg.mBody)
, mName(arg.mName)
{ }