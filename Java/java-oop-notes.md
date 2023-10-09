# Java Object Oriented Programming Notes

## Abstract vs Interface


**Abstract class** and **interface** are both used to define contracts in object-oriented programming, but there are some key differences between them.

Difference between abstract class and interface:

1. Definition:
	- An **abstract class** is a class that **cannot be instantiated** and can **contain both abstract and non-abstract methods**.
	- An **interface**, on the other hand, is a contract that specifies a set of methods that a class must implement.

2. Method implementation:
	- In an **abstract class**, some methods can be implemented, while others are left abstract, meaning that they have no implementation and must be overridden by concrete subclasses.
	- In contrast, all _methods_ in an **interface** are by _default abstract_ and must be implemented by any class that implements the interface.

3. Inheritance:

	A class can **inherit** from only **one abstract class**, but it can **implement multiple interfaces**. This is because an abstract class represents a type of object, while an interface represents a set of behaviors.

4. Access modifiers:
	- **Abstract classes** can have access modifiers such as public, protected, and private for their methods and properties.
	- While **interfaces** can only have public access.

5. Variables:
	An abstract class can have member variables, while an interface cannot.

In summary, abstract classes are used to provide a base class for concrete subclasses to inherit from, while interfaces are used to define a set of methods that a class must implement. Abstract classes can have implemented and abstract methods, while interfaces can only have abstract methods. Classes can inherit from only one abstract class, but can implement multiple interfaces.

As we know that abstraction refers to hiding the internal implementation of the feature and only showing the functionality to the users. i.e. showing only the required features, and hiding how those features are implemented behind the scene. Whereas, an Interface is another way to achieve abstraction in java. Both abstract class and interface are used for abstraction, henceforth Interface and Abstract Class are required prerequisites.
