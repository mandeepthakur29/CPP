// MULTIPLE INHERITANCE

class Base1 {
    // Base1 class definition
};

class Base2 {
    // Base2 class definition
};

class Derived : public Base1, public Base2 {
    // Derived class definition inheriting from Base1 and Base2
};



// MULTILEVEL INHERITANCE
class Base {
    // Base class definition
};

class Derived1 : public Base {
    // Derived1 class definition inheriting from Base
};

class Derived2 : public Derived1 {
    // Derived2 class definition inheriting from Derived1
};


// Explanation:

// Multiple Inheritance: The Derived class inherits from both Base1 and Base2. This means Derived has access to members of both Base1 and 
// Base2. However, the inheritance from Base1 is private, while the inheritance from Base2 is public.

// Multilevel Inheritance: The Derived class serves as a base class for another class, forming a hierarchy. In this example, Derived is
// not further derived, but it's possible to derive another class from Derived.