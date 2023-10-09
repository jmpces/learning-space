# Behavioral Pattern

1. **Chain of Responsibility Pattern**:
   - **Intent**: Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles it.
   - **Description**: The Chain of Responsibility pattern creates a chain of handler objects for a request. Each handler decides whether to process the request or pass it to the next handler in the chain.

2. **Command Pattern**:
   - **Intent**: Encapsulate a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations. It also allows for support of undoable operations.
   - **Description**: The Command pattern encapsulates a request as an object, which allows you to parameterize clients with requests, queue requests, and support undoable operations by storing command objects.

3. **Interpreter Pattern**:
   - **Intent**: Given a language, define a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.
   - **Description**: The Interpreter pattern is used to define a grammar for a language and provide an interpreter to interpret sentences in that language. It's typically used for tasks like parsing and evaluating expressions.

4. **Iterator Pattern**:
   - **Intent**: Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
   - **Description**: The Iterator pattern provides a way to access the elements of a collection (or aggregate) without exposing the underlying data structure. It separates the traversal of a collection from the collection itself.

5. **Mediator Pattern**:
   - **Intent**: Define an object that encapsulates how a set of objects interact. Promote loose coupling between objects by keeping them from referring to each other explicitly.
   - **Description**: The Mediator pattern centralizes communication between objects by introducing a mediator object. This reduces the direct connections between objects and promotes loose coupling.

6. **Memento Pattern**:
   - **Intent**: Without violating encapsulation, capture and externalize an object's internal state so that the object can be restored to this state later.
   - **Description**: The Memento pattern allows you to capture the internal state of an object without exposing its details. This state can then be stored externally, allowing the object to be restored to a previous state.

7. **Observer Pattern**:
   - **Intent**: Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
   - **Description**: The Observer pattern establishes a relationship between a subject (the object being observed) and one or more observers. When the subject's state changes, all registered observers are notified and updated.

8. **State Pattern**:
   - **Intent**: Allow an object to alter its behavior when its internal state changes. The object will appear to change its class.
   - **Description**: The State pattern allows an object to change its behavior when its internal state changes. This is achieved by encapsulating the different states as separate objects and allowing the context object to switch between them.

9. **Strategy Pattern**:
   - **Intent**: Define a family of algorithms, encapsulate each one, and make them interchangeable. Strategy lets the algorithm vary independently from clients that use it.
   - **Description**: The Strategy pattern defines a family of algorithms, encapsulates each algorithm, and makes them interchangeable. Clients can choose the appropriate strategy to use at runtime.

10. **Template Method Pattern**:
    - **Intent**: Define the skeleton of an algorithm in the superclass but let subclasses override specific steps of the algorithm without changing its structure.
    - **Description**: The Template Method pattern defines the structure of an algorithm in a superclass but allows subclasses to override specific steps of the algorithm. It promotes code reuse and ensures that the overall algorithm structure remains consistent.

11. **Visitor Pattern**:
    - **Intent**: Represent an operation to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.
    - **Description**: The Visitor pattern separates an algorithm from the objects it operates on. It allows you to define new operations without modifying the classes of the elements being operated upon by encapsulating the operations in visitor objects.

Each of these Behavioral Patterns addresses different aspects of managing object behavior and communication between objects, providing solutions to various design challenges related to object interaction and behavior encapsulation.