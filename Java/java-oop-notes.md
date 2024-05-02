# Java Object Oriented Programming Notes

## Abstract vs Interface

**Abstract class** and **Interface** are both used to define contracts in object-oriented programming, but there are some key differences between them.

Difference between abstract class and interface:

1. Definition:
	An abstract class is declared using the `abstract` keyword in its `class` definition.
	- An **Abstract Class** is a class that **cannot be instantiated** and can **contain both Abstract and Non-Abstract Methods**.
	- An **Interface**, on the other hand, is a contract that specifies a set of methods that a class must implement.


2. Method implementation:
	- In an **Abstract Class**, some methods can be implemented, while others are left abstract, meaning that they have no implementation and/ must be overridden by concrete subclasses.

		```java
		abstract class Shape {
			int color;

			// An abstract method
			abstract void draw(); // not implemented
			void non_abstract_method() {
				// ...
			}
		}

		class Circle extends Shape {
			@Override
			void draw() {
				// ... must be implemented
			}
		}
		```

	- In contrast, all _methods_ in an **Interface** are by _default abstract_ and must be implemented by any class that implements the interface.

		```java
		public interface Relatable {
			public int isLargerThan(Relatable other);
		}

		public class RectanglePlus implements Relatable {
			// ...
			@Override
			public int isLargerThan(Relatable other) {
				// ...           
			}
		}
		```

3. Inheritance:

	A class can **inherit** from only **one Abstract Class**, but it can **implement multiple interfaces**. This is because an Abstract Class represents a type of object, while an interface represents a set of behaviors.

4. Access modifiers:
	- **Abstract Classes** can have access modifiers such as public, protected, and private for their methods and properties.
	- While **Interfaces** can only have public access.

5. Variables:
	An Abstract Class can have member variables, while an interface cannot.

6. Rules:
	- **Abstract Class**
		1. An **instance** of an `abstract class` can not be created.
		2. **Constructors** are allowed.
		3. We can have an `abstract class` without any `abstract method`.
		4. There can be a `final` method in `abstract class` but any `abstract method` in class(`abstract class`) can not be declared as `final`  or in simpler terms `final` method can not be abstract itself as it will yield an error: “Illegal combination of modifiers: abstract and `final`”
		5. We can define `static` methods in an `abstract class`
		6. We can use the `abstract` keyword for declaring top-level classes (Outer class) as well as inner classes as abstract
		7. If a class contains at least one `abstract method` then compulsory should declare a class as abstract 
		8. If the **Child class** is unable to provide **implementation** to all `abstract method`s of the **Parent class** then we should declare that **Child class** as `abstract` so that the next level **Child class** should provide **implementation** to the remaining `abstract method`

In summary, Abstract Classes are used to provide a base class for concrete subclasses to inherit from, while interfaces are used to define a set of methods that a class must implement. Abstract Classes can have implemented and abstract methods, while interfaces can only have abstract methods. Classes can inherit from only one Abstract Class, but can implement multiple interfaces.

As we know that abstraction refers to hiding the internal implementation of the feature and only showing the functionality to the users. i.e. showing only the required features, and hiding how those features are implemented behind the scene. Whereas, an Interface is another way to achieve abstraction in java. Both Abstract Class and interface are used for abstraction, henceforth Interface and Abstract Class are required prerequisites.
