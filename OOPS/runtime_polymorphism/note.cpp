Runtime polymorphism, also known as dynamic polymorphism, is a fundamental concept in object-oriented programming (OOP). It allows a 
function or method to behave differently based on the actual type of the object it is called on. This behavior is determined at runtime 
rather than compile time, hence the term "runtime polymorphism."

Runtime polymorphism is achieved in C++ using virtual functions and inheritance. Here's how it works:

INHERITANCE: Runtime polymorphism relies on the concept of inheritance, where one class (the derived class) inherits from another class 
    (the base class). The derived class can override the virtual functions of the base class to provide its own implementation.

VIRTUAL FUNCTION: A virtual function is a member function of a base class that is declared with the virtual keyword. When a virtual 
    function is called through a pointer or reference to a base class object, the actual function to be executed is determined based on 
    the type of the object the pointer or reference points to.

LATE BINDING: The process of determining which function to call at runtime is known as late binding or dynamic binding. This allows for 
    flexibility in the behavior of the program, as the decision about which function to call is deferred until runtime.

BASE CLASS POINTERS OR REFERENCE: Runtime polymorphism is typically achieved by using pointers or references to base class objects. 
    This allows the same code to operate on objects of different derived classes, calling the appropriate overridden virtual functions 
    based on the actual type of the object.