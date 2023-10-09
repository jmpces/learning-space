# Structural Pattern

1. **Adapter Pattern**:
   - Intent: Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise due to incompatible interfaces.
   - Description: The Adapter pattern allows objects with incompatible interfaces to work together by providing a wrapper (the adapter) that translates one interface into another. It's useful when you have existing classes that can't be easily modified but need to collaborate with other classes.

2. **Bridge Pattern**:
   - Intent: Decouple an abstraction from its implementation so that the two can vary independently.
   - Description: The Bridge pattern separates an object's abstraction (what it does) from its implementation (how it does it). This decoupling allows you to change the abstraction and implementation independently, making the system more flexible.

3. **Composite Pattern**:
   - Intent: Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
   - Description: The Composite pattern allows you to create tree-like structures where individual objects and compositions of objects are treated the same way. This is particularly useful for building hierarchical structures of objects.

4. **Decorator Pattern**:
   - Intent: Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.
   - Description: The Decorator pattern lets you add behavior to objects dynamically, without altering their class. It involves creating a set of decorator classes that are used to wrap concrete components. This allows you to add new features to objects without changing their core implementation.

5. **Facade Pattern**:
   - Intent: Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.
   - Description: The Facade pattern provides a simplified interface to a complex system or set of classes. It hides the complexity of the subsystem and offers a single entry point for client code to interact with.

6. **Flyweight Pattern**:
   - Intent: Use sharing to support a large number of objects efficiently.
   - Description: The Flyweight pattern is used to reduce memory usage or computational overhead when dealing with a large number of similar objects. It involves separating the shared state (intrinsic) from the unique state (extrinsic) of objects, allowing many objects to share the same intrinsic state.

7. **Proxy Pattern**:
   - Intent: Provide a surrogate or placeholder for another object to control access to it.
   - Description: The Proxy pattern is used to control access to an object by providing a surrogate or placeholder for it. This can be useful for various purposes, such as lazy loading of expensive resources or adding security checks before accessing an object.

Each of these Structural Patterns addresses different aspects of organizing and composing objects in a software system, providing solutions to common design challenges related to object structure and collaboration.