#! /bin/bash
echo "who are you? "
read name
if [[ $name ]]; then
    echo "hello \"$name\" welcome to bash scripting"
else
    echo "I dont know you"
fi

echo "why are you here? "
read reason
if [[ $reason == "to learn" || $reason == "learn" || $reason == "learning" ]]; then
    echo "good for you"
else
    echo "wut?"
fi

echo "how old are you? "
read age
if [ "$age" ]; then
    if   (( $age <= 18 ));  then echo "too young"
    elif (( $age <= 30 ));  then echo "mid age"
    elif (( $age <= 70 ));  then echo "too old"
    elif (( $age <= 100 )); then echo "ancient"
    else echo "what?"
    fi
else
    echo I need inputs
fi

echo "Pick a color"
read color
if [[ $color == "red" ]]; then
    echo "wild"
elif [[ $color == "blue" ]]; then
    echo "cool"
elif [[ $green == "green" ]]; then
    echo "calm"
else
    echo "not in the choice"
fi







