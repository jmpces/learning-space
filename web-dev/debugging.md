# Debugging Techniques

## Chrome Monitor Event For An Element

1. Open Developer Mode
2. Select an HTML element to monitor its event
3. Open Console then type `$0`, this should be the html element you selected in step 2
4. pass this object to `monitorEvents($0)` to monitor events
4.5 you could also narrow down the events you want to monitor e.g.: `monitorEvents(document.body, 'mouse')`
5. unmonitorEvents($0)

## Find The Event Handler Function Of An Element

1. Open Developer Mode
2. Select an HTML element to find its event handler function
3. In the sub-window with `Stlyes` tab, change tab to `Event Listeners`
4. uncheck the checkbox `Ancestors`
5. check the checkbox `Framework listeners`
6. It should show the event handler of the selected element
