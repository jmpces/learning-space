# jQuery

## Get jQuery Version

```js
console.log('jQuery Version :', $().jquery);
```

## Selecting Elements

```js
// selects the whole html document
let WholeHTMLdocument = $("document");
// or
let WholeHTMLdocument = $(document);

// selects an html element using css selector syntax
let htmlElement = $("css-selector");
```

## Traversing Elements

```js
// get the next sibling
$("css-selector").next()

// get the previous sibling
$("css-selector").prev()

// get the parent
$("css-selector").parent()
```

## DOM Ready Event

Event handler that fires when the whole html document finised loading.

```js
$( handler ) // recommended for jQuery 3.0

$( document ).ready( handler )
$( "document" ).ready( handler )
$( "img" ).ready( handler )
$().ready( handler )

// As of jQuery 3.0, only the first syntax is recommended; the other syntaxes still work but are deprecated.

// This is also deprecated as of jQuery 1.8 and removed in jQuery 3.0. 
$(document).on( "ready", handler );
```

## Predefined Event Methods

```js
// 
htmlElement.click(eventHandler);

// triggers during mouse enter and leave (deprecated jQuery 3.3)
htmlElement.hover(eventHandler);
// use this instead
htmlElement.on("mouseenter mouseleave", eventHandler);
```

## Event using `on` method

**structure**

```js
$("css-selector").on("eventName", eventHandler);
$("css-selector").on("eventName1 eventName2 eventNameN", eventHandler);
```

**commonly used event names**

- `"click"`
- `"mouseenter"`
- `"mouseleave"`


## Set/Get Inner HTML (parses HTML)

```js
let oldHtmlContent = $("p").html();        // get
$("div").html("<p>Text inside a div</p>"); // set
```

## Set/Get Text Content (ignores HTML)

```js
let oldTextContent = $("p").text(); // get
$("p").text("new text content");    // set
```

Remember that setting contents is applicable to all tag/elements
in html but always remember that there are some elements that will
not display the text or inner html content between the opening
tag (`<>`) and closing (`</>`) html tags like `<input>`.

## Set/Update Values Of Inputs

## Get Values From Inputs

## Adding Elements (parses HTML)

```js
// add to front
$("body").prepend("<h1>Added Header using jQuery</h1>");

// add to last
$("body").append("<h1>Added Header using jQuery</h1>");
```

## Removing Elements

```js
// will remove all divs (all matched css-selector)
$("div").remove();
```

## Removing All Contents of an HTML tag/element

```js
$("body").empty();
```

## Enclosing Elements Inside Another Element

```js
// will wrap all paragraphs inside a div tag
$("p").wrap("<div class='className' otherHtmlAttr='value'>");
```

## Hiding/Showing Elements

Most of these method has overloads where you can pass an
argument like **duration** (how fast the animation will execute), type of **easing**, and **event handlers**.

```js
$("css-selector").show();
$("css-selector").hide();
$("css-selector").toggle(); // hide if shown and show if hidden

$("css-selector").slideDown(); // show
$("css-selector").slideUp();   // hide
$("css-selector").slideToggle(); // hide if shown and show if hidden

$("css-selector").fadeIn(); // show
$("css-selector").fadeOut(); // hide
$("css-selector").fadeToggle(); // hide if shown and show if hidden
```

The hide methods above will set the dislay of an html element to:

```css
display: none
```

## Styling

```js
$("h1").css("border", "solid 1px red");
```

## Manipulating HTML Attributes

**html classes**

```js
// add class
$("css-selector").addClass("class-name");

// remove class
$("css-selector").removeClass("class-name");

// add/remove class
$("css-selector").toggleClass("class-name");
```
