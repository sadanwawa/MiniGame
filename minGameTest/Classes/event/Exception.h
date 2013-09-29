
#ifndef minGameTest_CCException_h
#define minGameTest_CCException_h

template<typename _Exception>
void throwException(char const* format, ...)
{
    va_list arglist;
    
    va_start(arglist, format);
    
    char buff[1024] = { 0 };
    
    vsprintf(buff, format, arglist);
    
    va_end(arglist);
    
    throw _Exception(buff);
}

#endif
