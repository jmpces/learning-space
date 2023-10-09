# **Lines - Analytical Geometry**

## **Equation Notes**
- Multiply both sides of the equation to $-1$ if the front
(leftmost) term is negative, to make it better looking.

    The given two equations below are **equal** even though their signs 
    is not the same, we can achieve the second equation by multiplying 
    both sides of the first equation to $-1$:

    - $-2x + y = -3$
    - $2x - y = 3$

## **Standard form** - One variable linear equation

$ax = b$

## **Standard form** - Two variable linear equation

$Ax + By = C$


## **General form**

$Ax + By + C = 0$

## **Intercept Form**

$\dfrac{x}{a} + \dfrac{y}{b} = 1$

$a$ is the **x intercept**

$b$ is the **y intercept**

## **Slope intercept form**

$y = mx + b$

$m$ is the **slope**

$b$ is the **y intercept**


## **Slope formula** - for two given points

<!-- \dfrac means that the fraction is set in displaystyle

\tfrac means that the fraction is set in textstyle

with \frac: the actual context implies the decision above -->

$m = \dfrac{rise}{run}$

$m = \dfrac{y_2 - y_1}{x_2 - x_1}$

## **Point Slope Form**

Use to find the equation of a line when a **slope** $m$, and a **vertex/point** $(x_1, y_1)$ is the only given variables.

$y - y_1 = m(x - x_1)$

$y - b = m(x - a)$

## **Two Point Slope Form**

$y - y_1 = \dfrac{(y_1 - y_2)}{(x_1 - x_2)}(x - x_1)$

## **Midpoint formula** - give two points

$(x_m, y_m)= \left( \dfrac{x_1+x_2}{2},\dfrac{y_1+y_2}{2} \right)$

## **Distance formula**

$d = \sqrt{ (x_2-x_1)^2 + (y_2-y_1)^2 }$

## **Angle Between two lines theorem**

$\tan \theta = \dfrac{m_2-m_1}{1+m_1m_2}$

$angle = \tan^{-1}(\tan \theta)$

counter-clockwise:

$m_1 = src$

$m_2 = dest$

## **Direct distance from a line to a point**

$d = \dfrac{Ax_1+By_1+C}{\pm \sqrt{A^2+B^2}}$

Denominator's sign should be the same as $B$

## **Intersection of a line**

**Warning**: I have come up with this formula on my own,
this might not be accurate or correct, I only simplified the
given steps on finding the intersect of two lines into a formal.

$$
intersect = \left(
    \dfrac{B_2C_1-B_1C_2}{A_1B_2-A_2B_1},
    \dfrac{A_2C_1-A_1C_2}{B_1A_2-B_2A_1}
\right)
$$

## **What is a Linear Equation?**

- There should be **no exponent/power** that is greater than $1$

- There should be **no multiplication** of variables $x$ and $y$
in a ***single term*** for **both sides** of the equation.

- The variables $x$ and $y$ should **not be a denominator**.

    The following examples are not linear equation:

    - The equation $-3/y = x$ is equivalent to $-3 = xy$, where a multiplication of both $x$ and $y$ variables is present
    on the right side of the equation, hence this is not a linear equation.

    - $xy = 7$

## **Check if a point lies in the given straight linear**

We can do this by just substitution the values of x and y
in the standard two variable form, and checking if it will be equal to C of the line

## **Graphing Linear Equation**

Ways to graph a linear equation

- **Table of values** - this is the act of substitution $x$ value to the equation to get the points.

- **Intercept Method**
    - Let $y$ be $0$ to find **x intercept** : $(x, 0)$
    - Let $x$ be $0$ to find **y intercept** : $(0, y)$

    Graph the 2 points in x-intercept and y-intercept.

## **(Optional) Converting Fractional Terms in an equation to Whole Terms**

Sometimes we can remove fractions in an equation:

1. We need to find the LCD of all the terms
in an equation (yes, including whole numbers and their /1)
2. multiply the numerator and denominator to a factor where the product of the denominator and that factor should be the LCD that you found in step 1 (do this for each term when necessary, sometimes there is a one term that has already the LCD, so you leave that term)
3. After making all the denominator of the equation the same, multiply both sides to the LCD/(denominator are all the same now) to cancel the denominator or the lower parts of the fractional terms.

## **Simplify Fractions**

$$\frac{\left(\dfrac{1}{3}\right)}{\left(\dfrac{3}{5}\right)} = \dfrac{1}{3} \cdot \dfrac{5}{3} = \dfrac{5}{9}$$

## **Convert Standard form to Intercept form**

- $Ax + By = C$

- $\dfrac{x}{a} + \dfrac{y}{b} = 1$

    $a$ is the **x intercept**

    $b$ is the **y intercept**

solution:

$$\begin{align}
Ax + By &= C \\
\frac{Ax}{C} + \frac{By}{C} &= \frac{C}{C} \\
\frac{Ax}{C} + \frac{By}{C} &= 1 \\
\frac{x}{\dfrac{C}{A}} + \dfrac{y}{\dfrac{C}{B}} &= 1
\end{align}$$

## **Intercept form to Standard form**

- $\dfrac{x}{a} + \dfrac{y}{b} = 1$
- $Ax + By = C$

**Warning**: I have come up with this formula on my own,
this might not be accurate or correct, I interpreted my
own steps when converting the intercept form to standard form.

version 1:

$$
\begin{align}
\dfrac{x}{a} + \dfrac{y}{b} &= 1 \\
\newline
\dfrac{x}{lcm(a,b)} + \dfrac{y}{lcm(a,b)} &= \frac{1}{lcm(a,b)} \\
\newline
\dfrac{\dfrac{lcm(a,b)}{a}x}{lcm(a,b)} +
\dfrac{\dfrac{lcm(a,b)}{b}y}{lcm(a,b)} &=
\frac{\dfrac{lcm(a,b)}{1}}{lcm(a,b)} \\
\newline
lcm(a,b)\cdot\left(\dfrac{\dfrac{lcm(a,b)}{a}x}{lcm(a,b)} +
\dfrac{\dfrac{lcm(a,b)}{b}y}{lcm(a,b)}\right) &=
\left(\frac{\dfrac{lcm(a,b)}{1}}{lcm(a,b)}\right) \cdot lcm(a,b) \\
\newline
\cancel{lcm(a,b)}\cdot\left(\dfrac{\dfrac{lcm(a,b)}{a}x}{\cancel{lcm(a,b)}} +
\dfrac{\dfrac{lcm(a,b)}{b}y}{\cancel{lcm(a,b)}}\right) &=
\left(\frac{\dfrac{lcm(a,b)}{1}}{\cancel{lcm(a,b)}}\right) \cdot \cancel{lcm(a,b)} \\
\newline
\dfrac{lcm(a,b)}{a}x +
\dfrac{lcm(a,b)}{b}y &=
\dfrac{lcm(a,b)}{1} \\
\newline
\dfrac{lcm(a,b)}{a}x +
\dfrac{lcm(a,b)}{b}y &=
lcm(a,b) \\
\end{align}
$$

version 2:

$$
\begin{align}
\dfrac{x}{a}+\dfrac{y}{b} &= 1 \\
\newline
a \cdot \left( \dfrac{x}{a}+\dfrac{y}{b} \right) &= 1 \cdot a \\
\newline
\dfrac{ax}{a}+\dfrac{ay}{b} &= a \\
\newline
\dfrac{\cancel{a}x}{\cancel{a}}+\dfrac{ay}{b} &= a \\
\newline
x+\dfrac{ay}{b} &= a \\
\newline
b \cdot \left( x+\dfrac{ay}{b} \right) &= a \cdot b \\
\newline
bx+\dfrac{bay}{b} &= ab \\
\newline
bx+\dfrac{\cancel{b}ay}{\cancel{b}} &= ab \\
\newline
bx+ay &= ab \\
\end{align}
$$

## **Getting the equation of the bisector of a given line segment AB**

1. get the slope using the slope formula
2. get the

## **Review**
- GCD
- LCD
- GCM
- LCM
- GCF
- LCF














