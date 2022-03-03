//Header file: stackADT.h 

#ifndef H_StackADT
#define H_StackADT
  
template <class Type>
class stackADT 
{
public:
    virtual void p1() = 0; 
    virtual bool p2() const = 0;
    virtual bool p3() const = 0;
    virtual void p4(const Type& newItem) = 0;
    virtual Type p5() const = 0;
    virtual void p6() = 0;
};
        
#endif
