# **React.js**

## **Contents**
- [Installation](#installation)
- [Class Components](#class-components)
- [Function Components](#function-components)
- [Using a Component](#using-a-component)
- [Passing Data to a Child Component](#passing-data-to-a-child-component)
- [Retrieving Data from Parent Component](#retrieving-data-from-parent-component)
- [Manipulating States In A Component](#manipulating-states-in-a-component)
- [Updating States On Asynchronous Applications](#updating-states-on-asynchronous-applications)
- [Component/Element Events](#componentelement-events)
- [Preventing Default HTML Behaviors](#preventing-default-html-behaviors)
- [Manually Binding A Method](#manually-binding-a-method)
- [Automatically Binding A Method](#automatically-binding-a-method)
- [Bindings When Using A Function Component](#bindings-when-using-a-function-component)
- [Passing Arguments To Event Handlers](#passing-arguments-to-event-handlers)
- [Conditional Rendering](#conditional-rendering)
- [Conditional Rendering Using Element Variables](#conditional-rendering-using-element-variables)
- [Conditional Rendering Using Inline JSX if Statement](#conditional-rendering-using-inline-jsx-if-statement-with-logical-and--operator)
- [Conditional Rendering With Ternary Operator](#conditional-rendering-with-ternary-operator)
- [Immediate Nesting Curly Braces Is Not Allowed](#immediate-nesting-curly-braces--is-not-allowed-in-an-element)
- [Proper Way To Nest Curly Braces](#proper-way-to-nest-curly-braces)
- [Preventing Components From Rendering](#preventing-components-from-rendering)
- [Rendering Multiple Components](#rendering-multiple-components)
- [Building Multiple Components](#building-multiple-components)
- [Keys For Elements Collections](#keys-for-element-collections)
- [Keys Are Actually Not Element Attribute](#keys-are-actually-not-element-attributes)
- [Setting Values Of Input Tags As State](#setting-values-of-input-tags-as-state)
- [The `textarea` Element](#the-textarea-tag)
- [The `select` Element](#the-select-tag)
- [Accessing Other Properties Of Input Elements](#accessing-other-properties-of-input-elements)
- [Handling Multiple Inputs](#handling-multiple-inputs)
- [Adding A New State Property](#adding-a-new-state-property)
- [Controlled Input `null` Value](#controlled-input-null-value)


## **Installation**

- **mobile development (React Native)**
    ```
    npm install -g expo-cli
    expo init YourApp
    expo start
    ```

- **Web Applications (ReactJS)**
    ```
    npx create-react-app app-name
    or
    yarn create react-app app-name
    ```

## **The Root Div**

We can create a React `root` div instance using the
React DOM, this will be our Main Component, and this is
where we will load all of our other subcomponents.

```jsx
import React from 'react'
import ReactDOM from 'react-dom/client'

const root = ReactDOM.createRoot(document.getElementById('root'))

root.render(<OurMainComponent />)
```

We should also keep in mind that it is also possible to
create multiple react `root`s, this is common for old web
apps that was not developed using react at the first place
but at some point they started to integrate react on some
parts of their existing web app.

```jsx
const root1 = ReactDOM.createRoot(document.getElementById('root1')
const root2 = ReactDOM.createRoot(document.getElementById('root2')
const root3 = ReactDOM.createRoot(document.getElementById('root3')

root1.render(<MainComponentA />)
root2.render(<MainComponentB />)
root3.render(<MainComponentC />)
```

## **Class Components**

  ```jsx
  class Clock extends React.Component {
    constructor(props) {
      super(props)
      this.state = { date: new Date() }
    }

    componentDidMount() {
      this.timerID = setInterval(() => this.tickEventHandler(), 1000)
    }

    componentDidUpdate(previousProps, previousState) {
      document.title = `time : ${this.state.date.toLocaleTimeString() }`
    }

    componentWillUnmount() {
      clearInterval(this.timerID)
    }

    tickEventHandler() {
      this.setState({ date: new Date() })
    }

    render() {
      return (
        <div>
          <h2>Time : {this.state.date.toLocaleTimeString()}.</h2>
        </div>
      )
    }
  }
  ```

## **Function Components**

```jsx
function Clock (props) {
  const [ date, setDate ] = React.useState(new Date())

  React.useEffect(() => { // componentDidMount equivalent
    const timerID = setInterval(() => tickEventHandler(), 1000)
    
    function tickEventHandler () {
      setDate(new Date())
    }

    return () => { // componentWillUnmount equivalent
      clearInterval(timerID)
    }
  }, []) // <- no dependency

  // componentDidUpdate equivalent - separation of concerns
  React.useEffect(() => {
    document.title = `time : ${ date.toLocaleTimeString() }`
  }, [date]) // <- dependent on date - will run when date change

  return (
    <div>
      <h2>Time : { date.toLocaleTimeString() }.</h2>
    </div>
  )
}
```

When creating a simple component, `function` components tends to be
easier to create and use than a `class` component.

In `class` components we need to use the
`render()` method, and the `this.props` keyword to access the
information passed to it via props (there is a way to directly
pass props without using a constructor), we also need to
extend the `React.Component` when using a class.

On the other hand, when using functions, we can use the `props`
argument directly not `this.` keyword needed, there is no `render()`
method property, and `extends React.Component` is not needed.

Though when simulating the `componentDidMount`, `componentDidUpdate`,
and `componentWillUnmount` of **class components** for **function
components** we need to use **Hook methods** like `useState` and 
`useEffect`.

## **Using a Component**

```jsx
function ParentComponent (props) {
    return (
        <div>
            <h1>Parent Component</h1>
            <div>
                <ChildComponent />
            </div>
        </div>
    )
}
```


Say for example we have a parent component and a child component,
if we want to render the child component inside our parent component
we just need to call the child component inside angles brackets `< />`.


## **Passing Data To A Child Component**

We can pass data to a child component using `props`, usually
this data being passed are **states** of a parent component.

```jsx
function ParentComponent (props) {
  return (
      <div>
          <h1>Parent Component</h1>
          <div>
              <ChildComponent
                  // props name and value
                  propPropertyName={ 'I am a js string' }
                  anotherOne={<p>'I am an element'</p>}
              />
          </div>
      </div>
  )
}
```

## **Retrieving Data From Parent Component**

We can retrieve data from a parent component by accessing the
- Property `this.props` for `class` components.
- Parameter of `function` components, usually we
name it `props`.

```jsx
// class component
class ChildComponent extends React.Component {
  render() {
      return (
          <div>
              <h1> { this.props.propPropertyName } </h1>
              { this.props.anotherOne }
          </div>
      )
  }
}

// function component
function ChildComponent (props) {
    return (
        <div>
            <h1> { props.propPropertyName } </h1>
            { props.anotherOne }
        </div>
    )
}
```

In **`class`** components, it is **optional** to create a constructor
that will catch the **`props`** argument, because a **`this.prop`**
is already created for us.

## **Manipulating States in a Component**

React component can be **stateful** or **stateless**, stateful
components are components that contains their own data, while
stateless components only relies on to the `props` being passed to
them by a parent component.

- **Class Components**
    ```jsx
    class App extends React.Component {
      constructor() {
        super()
        this.state = {
          date: new Date().toLocaleTimeString(),
          millisec: new Date().getTime()
        }

        setInterval(() => this.setState({ date: new Date().toLocaleTimeString() }), 1000)
        setInterval(() => this.setState({ millisec: new Date().getTime() }), 1)
      }

      render() {
        return (
          <div>
            <h2>It is { this.state.date }</h2>
            <h2>Milliseconds Passed : { this.state.millisec }</h2>
          </div>
        )
      }
    }
    ```

- **Function Component**
    ```jsx
    function App() {
      const [ date, setDate ] = React.useState(new Date().toLocaleTimeString())
      const [ millisec, setMilliSec ] = React.useState(new Date().getTime())

      setInterval(() => setDate(new Date().toLocaleTimeString()), 1000)
      setInterval(() => setMilliSec(new Date().getTime()), 1)

      return (
        <div>
          <h2>It is { date }</h2>
          <h2>Milliseconds Passed : { millisec }</h2>
        </div>
      )
    }
    ```

State variables can hold objects and arrays just fine, so you can still group
related data together. However, unlike **`this.setState`** in a **`class`**,
updating a **state variable** in a function **always replaces** it instead of
merging it.
(https://reactjs.org/docs/hooks-state.html#tip-using-multiple-state-variables)

## **Updating States On Asynchronous Applications**

https://reactjs.org/docs/state-and-lifecycle.html#state-updates-may-be-asynchronous

React may batch multiple `setState()` calls into a single update for performance.

And since `this.props` and `this.state` may be updated asynchronously, we should not rely on their values when calculating the next state.

For example, this code may fail to update the correct value
of the counter because the value is calculated right away.

If by chance React decided to batch this `setState` call, and say for 
example an asynchronous update occurred changing the value of
`this.state.counter` and `this.props.increment` before the previous
batch was applied, at that point the batch `setState` contains an
outdated value of `counter` and `increment`.

```jsx
// Wrong
this.setState({
  counter: this.state.counter + this.props.increment,
});
```

```jsx
// Correct
this.setState(function(state, props) {
  return {
    counter: state.counter + props.increment
  };
});
```

To minimize this problem, we can delay the calculation in the
`setState` call using a function, this function will not be
executed right away and only when the batch is applied it will
return a calculated new `counter` value.

## **Component/Element Events**

**React** event names are in **camelCase** style, e.g. **`onclick`**.

In **JSX** we can assign an **event handler function** to an element
by assigning a function directly inside a curly brace **`={}`**.

Example:

```jsx
function NextButton (props) {
  return (
    <button onClick={ props.nextPicture }>
      Next
    </button>
  )
}
```

On the example above, the **`<button>`** tag is our JSX element (which are similar 
to HTML elements), the **`onClick`** is the event name, and the
**`props.nextPicture`** is an event handler function that gets 
executed whenever a user clicked the `NextButton` component's `<button>`.

If an event handler has an argument, we can do it this way.

```jsx
function NextButton (props) {
  return (
    <button onClick={ () => {
        props.nextPicture(args...)
    }>
      Next
    </button>
  )
}
```

## **Preventing Default HTML Behaviors**

To prevent a default behavior in a **React JSX element** we use the method
**`e.preventDefault()`** in our event handler.

```jsx
function Form() {
  function handleSubmit(e) {
    e.preventDefault();
    console.log('You clicked submit.');
  }

  return (
    <form onSubmit={handleSubmit}>
      <button type="submit">Submit</button>
    </form>
  );
}
```

## **Manually Binding A Method**

When creating an event handler method for a **`class` component** it should
be bounded to the class itself.

One way to do this _explicitly_ is by manually binding a method inside a class
**`constructor`**.

```jsx
class Toggle extends React.Component {
  constructor(props) {
    super(props);
    this.state = {isToggleOn: true};

    // manual binding
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    this.setState(prevState => ({ isToggleOn: !prevState.isToggleOn }));
  }

  render() {
    return (
      <button onClick={this.handleClick}>
        {this.state.isToggleOn ? 'ON' : 'OFF'}
      </button>
    );
  }
}
```

## **Automatically Binding A Method**

One way to bound a method to a **`class` component** _implicitly_ is by
using a
[**Public Instance Field**](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes/Public_class_fields#public_instance_fields).

```jsx
class Toggle extends React.Component {
  constructor(props) {
    super(props);
    this.state = {isToggleOn: true};
  }

  // automatic binding
  handleClick = (e) => {
    this.setState(prevState => ({ isToggleOn: !prevState.isToggleOn }));
  }

  render() {
    return (
      <button onClick={this.handleClick}>
        {this.state.isToggleOn ? 'ON' : 'OFF'}
      </button>
    );
  }
}
```

React documentation says that this syntax is enabled by default in the 
**Create React App**. (I don't know if that is the case if you set up react
from scratch)

## **Bindings When Using A Function Component**

```jsx
function Toggle (props) {
  const [isToggleOn, setToggle] = React.useState(false)

  function handleClick (e) {
    setToggle((prevState) => !prevState)
  }

  return (
    <button onClick={handleClick}>
      {isToggleOn ? 'ON' : 'OFF'}
    </button>
  )
}
```

On some cases where we don't want to recreate the event handler function
every time we re-render, similar to class components, we can instead use
the `useCallback` hook to create our event handler.

```jsx
const handleClick = React.useCallback(() => {
  setToggle((prevState) => !prevState)
}, [])
```

## **Passing Arguments To Event Handlers**

These two examples are equivalent.

At the first example we pass an arrow function that uses the event
handler function inside it, in this case the arrow function is
actually the real event handler.

```jsx
<button onClick={(e) => this.deleteRow(id, e)}>Delete Row</button>
<button onClick={this.deleteRow.bind(this, id)}>Delete Row</button>
```

In both cases, the **`e`** argument representing the React event will be
passed as a second argument after the **`ID`**. With an arrow function, we 
have to pass it explicitly, but with **`bind`** any further arguments are 
automatically forwarded.

## **Conditional Rendering**

Conditional rendering is also supported in React like a normal
programming language that has conditionals.

```jsx
function UserGreeting(props) {
  return <h1>Welcome back!</h1>;
}

function GuestGreeting(props) {
  return <h1>Please sign up.</h1>;
}

function GreetingTernary(props) {
  return props.isLoggedIn ? <UserGreeting /> : <GuestGreeting />;
}

function GreetingIfElse(props) {
  if (props.isLoggedIn) {
    return <UserGreeting />
  } else {
    return <GuestGreeting />
  }
}
```

## **Conditional Rendering Using Element Variables**

Remember that we can always store an element to a local variable inside a scope, or a public member of a class.

```jsx
render() {
  let button; // <- Element Variable
  
  if (this.state.isLoggedIn) {
    button = <LogoutButton onClick={this.handleLogoutClick}/>;
  } else {
    button = <LoginButton onClick={this.handleLoginClick}/>;
  }

  return (
    <div>
      <Greeting isLoggedIn={isLoggedIn} />
      {button}
    </div>
  );
}
```

## **Conditional Rendering Using "Inline JSX If Statement" with "Logical AND (&&) Operator"**

```jsx
function App (props) {
  return (
    <div>
      {props.show &&
        <h1>I'm' Here!!!</h1>
      }
    </div>
  )
}

root.render(<App show={false}/>)
```

## **Conditional Rendering With Ternary Operator**

```jsx
function App (props) {
    return (
      <div>
        { <h1>You have {props.passed ? 'PASSED' : 'FAILED'}</h1> }
        {
          props.passed
            ? <h2>Wait for the next instruction</h2>
            : <h2>We are not accepting you</h2>
        }
      </div>
    )
}
```

## **Immediate Nesting Curly Braces `{}` Is Not Allowed In An Element**

The following component will throw and error since it has 
an immediate nested curly braces inside it.

```jsx
class App extends React.Component {
  render() {
    return (
      <div>
        { <h1>You have {this.props.passed ? 'PASSED' : 'FAILED'}</h1>
          {
            this.props.passed
              ? <h2>Wait for the next instruction</h2>
              : <h2>We are not accepting you</h2>
          }
        }
      </div>
    )
  }
}
```

## **Proper Way To Nest Curly Braces `{}`**

We need to enclose every curly braces inside a component/
element for the nesting to work.

```jsx
function ProperlyNested (props) {
  return (
    <div>
      <h1>Main</h1>
      {
        <div>
          <h2>Sub Main</h2>
          {
            <div>
              <h3> { <span>Main Message</span> } </h3>
            </div>
          }
        </div>
      }
    </div>
  )
}
```

You see in the example code above, the second `{}` is
enclosed inside the `<div></div>` tag, and the third curly
braces is enclosed inside the `<h3></h3>` tag.

## **Preventing Components From Rendering**

To prevent a component from rendering, we simply return **`null`**
for **`function` component**.

And returning **`null`** in a **`class` component**s `render()` method.

```jsx
function Island (props) {
  if (props.hightide) {
    return null
  } else {
    return <h1>A Lush Green Island</h1>
  }
}
```

## **Rendering Multiple Components**

In react, rendering a list of JSX elements is possible.

```jsx
function Students (props) {
  const Names = [
    <li> Micha </li>,
    <li> Hannah </li>,
    <li> James </li>,
    <li> Henry </li>
  ]

  return ( <ul> { Names } </ul>)
}
```

## **Building Multiple Components**

We can build multiple components in react with standard or custom
JavaScript functions or methods, in this example we are going to use the
array method **`map`** to build an **array JSX element** and then 
**render** it.

```jsx
function DisplayNames (props) {
  return (
    <ol> { props.names.map((name) => <li> { name } </li>) } </ol>
  )
}

root.render(<DisplayNames names={['Micha','Hanna','James','Henry']} />)
```

If you look at the browser console, this will give you a warning because
element keys are not provided in the JSX array collection.

## **Keys For Element Collections**

**Keys** help React identify which items have changed, added, 
or removed. **Keys** should be given to the elements inside 
the array to give the elements a stable identity, this also
requires the key (obviously) to be **unique** in a specific
scope.

```jsx
function DisplayNames (props) {
  return (
    <ol> {
      props.names.map(
        function (name, index) {
          return <li key={index}> { name } </li>
        }
      )
    } </ol>
  )
}
```

Same as the previous example, but with **index** as **keys**.

One important side note though, **AVOID USING INDEX AS KEYS**.

## **Keys Are Actually Not Element Attributes**

Key serves as a hint to React, but they are not added to the 
JSX element or component, meaning you will not be able to see
the **`key`** attribute keyword in the resulting HTML element/
tag of the final HTML output.

## **Setting Values Of Input Tags As State**

In react, the **value** of **input tags** should be stored in a 
**component state**, In order to do this, we designate an **event 
handler** every time an _input event_ happens on those **input tags**.

We can get the **input tag values** using the **event property**;
```event.target.value```.

Then we can just extract those data in the `this.state` whenever needed,
these types of components are called **controlled components** in react.

- **Controlled Class Component**

  ```jsx
  class NameForm extends React.Component {
    constructor(props) {
      super(props);
      this.state = {value: ''};

      this.handleChange = this.handleChange.bind(this);
      this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleChange(event) {
      this.setState({value: event.target.value});
    }

    handleSubmit(event) {
      alert('A name was submitted: ' + this.state.value);
      event.preventDefault();
    }

    render () {
      return (
        <form onSubmit={this.handleSubmit}>
          <label>
            Name:
            <input type="text" value={this.state.value} onChange={this.handleChange} />
          </label>
          <input type="submit" value="Submit" />
        </form>
      );
    }
  }
  ```

- **Controlled Function Component**

  ```jsx
  function NameForm () {
    const [value, setValue] = React.useState('')

    const handleChange = function (event) {
      setValue(event.target.value)
    }

    const handleSubmit = function (event) {
      alert('A name was submitted: ' + value)
      event.preventDefault()
    }

    return (
      <form onSubmit={handleSubmit}>
        <label>
          Name:
          <input type="text" value={value} onChange={handleChange} />
        </label>
        <input type="submit" value="Submit" />
      </form>
    )
  }
  ```

## **The `textarea` Tag**
 In react we can also access its contents the same way we access most
 `<input>` tags.

 ##  **The `select` Tag**

 We can also access the selected value in the `event.target.value`
 property of the event handler of `select` tag.

 ```jsx
 <select onChange={onSelection}>
  <option value="grapefruit">Grapefruit</option>
  <option value="lime">Lime</option>
  <option value="coconut">Coconut</option>
  <option value="mango">Mango</option>
</select>
```

## **Accessing Other Properties Of Input Elements**

Aside from the **value**, We can also access **some** (not all)
**properties of elements** in react... Like the `<input>` by using the dot
operator and the specific **property name**.

```jsx
function AccessProperties (props) {
  const OnChangeEvent = function (e) {
    let display = ''
    display += `type: ${e.target.type}\n`
    display += `className: ${e.target.className}\n`
    display += `name: ${e.target.name}\n`
    display += `value: ${e.target.value}\n`
    console.log(display)
  }

  return (
    <div>
      <input
        className={'inputs'}
        name={'a-text-field'}
        type={'text'}
        onChange={OnChangeEvent}
      ></input>
    </div>
  )
}
```

## **Handling Multiple Inputs**

Here are some example how you can handle multiple input.

- **From the official react main guide documentation**

  ```jsx
  class Reservation extends React.Component {
    constructor(props) {
      super(props);
      this.state = {
        isGoing: true,
        numberOfGuests: 2
      };

      this.handleInputChange = this.handleInputChange.bind(this);
    }

    handleInputChange(event) {
      const target = event.target;
      const value = target.type === 'checkbox' ? target.checked : target.value;
      const name = target.name;

      this.setState({
        [name]: value
      });
    }

    render() {
      return (
        <form>
          <label>
            Is going:
            <input
              name="isGoing"
              type="checkbox"
              checked={this.state.isGoing}
              onChange={this.handleInputChange} />
          </label>
          <br />
          <label>
            Number of guests:
            <input
              name="numberOfGuests"
              type="number"
              value={this.state.numberOfGuests}
              onChange={this.handleInputChange} />
          </label>
        </form>
      );
    }
  }
  ```

- **My wild experimentation**

  ```jsx
  class InputTagExamples extends React.Component {
    constructor() {
      super()
      this.state = {}
    }

    handleInputChange = (event) => {
      this.setState({ [event.target.type]: event.target.value })
      console.log(event.target)
    }

    render () {
      let inputValues = []
      for (let key in this.state) {
        inputValues.push(<li keys={key}> { `${key} : ${this.state[key]}` } </li>)
      }

      return (
        <div className='main-div'>
          <div className='input-tags'>
            <input onInput={this.handleInputChange} type={'button'} value={'Show All Values'}/>
            <input onInput={this.handleInputChange} type={'checkbox'}/>
            <input onInput={this.handleInputChange} type={'color'}/>
            <input onInput={this.handleInputChange} type={'date'}/>
            <input onInput={this.handleInputChange} type={'datetime-local'}/>
            <input onInput={this.handleInputChange} type={'email'}/>
            <input onInput={this.handleInputChange} type={'file'}/>
            <input onInput={this.handleInputChange} type={'hidden'}/>
            <input onInput={this.handleInputChange} type={'image'} alt='image-input'/>
            <input onInput={this.handleInputChange} type={'month'}/>
            <input onInput={this.handleInputChange} type={'number'}/>
            <input onInput={this.handleInputChange} type={'password'}/>
            <input onInput={this.handleInputChange} type={'radio'}/>
            <input onInput={this.handleInputChange} type={'range'}/>
            <input onInput={this.handleInputChange} type={'search'}/>
            <input onInput={this.handleInputChange} type={'tel'}/>
            <input name="test" onInput={this.handleInputChange} type={'text'}/>
            <input onInput={this.handleInputChange} type={'time'}/>
            <input onInput={this.handleInputChange} type={'url'}/>
            <input onInput={this.handleInputChange} type={'week'}/>
            <textarea onInput={this.handleInputChange}/>
          </div>
          <div className='value-div'>
            <ul> {inputValues} </ul>
          </div>
        </div>
      )
    }
  }
  ```

## **Adding A New State Property**

When adding a new **property** in our **state**, we can use the
**ES6 - computed property name syntax**:

```jsx
this.setState({
  [key]: value
})
```

This is equivalent to the ES5 syntax:
 
```jsx
let NewState = {};
NewState[name] = value;
this.setState(NewState);
```

## **Controlled Input `null` Value**

Specifying the `value` prop on a **controlled component** prevents the
user from changing the input unless you desire so. If you’ve specified a 
`value`, but the input is still editable, you may have accidentally set 
value to `undefined` or `null`.

```jsx
ReactDOM.createRoot(mountNode).render(<input value="hi" />);
```

## **Component Containment**

Using the `prop.children` we can directly pass tag/elements and child
components to a parent component by enclosing them within the parent
component tag in the parent component. e.g.
_`<> contain components... </>`_

```css
.fancy-border { border: 0.2em solid black; }
```

```jsx
function FancyBorder (props) {
  return (
    <div className='fancy-border'>
      { props.children }
    </div>
  )
}

function App () {
  return (
    <FancyBorder>
      <h1>Title</h1>
      <p>Main content ...</p>
      <p>The end.</p>
    </FancyBorder>
  )
}
```

Though If we need a more customized way of placing children inside a
parent component, we can just directly pass a child component through
child property.

```jsx
function SplitPane(props) {
  return (
    <div className="SplitPane">
      <div className="SplitPane-left">
        {props.left}
      </div>
      <div className="SplitPane-right">
        {props.right}
      </div>
    </div>
  );
}

function App() {
  return (
    <SplitPane
      left={
        <Contacts />
      }
      right={
        <Chat />
      } />
  );
}
```