## **Ellipse**

### **Parts of Ellipse**

- $Center(h,k)$ - the center point of the ellipse.

- **major axis** - where the maximum distance of two vertices of the ellipse lies, could either be on the $x$ or $y$ axis.
    - size = $2a$

- **minor axis** - where the minimum distance of two vertices of the ellipse lies, could either be on the $x$ or $y$ axis.
    - size = $2b$

- $c^2 = a^2 - b^2$

- $\dfrac{2b^2}{a}$ = length of latus rectum


### **Standard Equation**

- **If** $(x-h)^2$ 's denominator is **greater than** $(y-k)^2$ 's denominator then : the ellipse is **horizontal**

$$
\frac{(x-h)^2}{a^2}
+
\frac{(y-k)^2}{b^2}
= 1
$$

- **If** $(x-h)^2$ 's denominator is **less than** $(y-k)^2$ 's denominator then : the ellipse is **vertical**

$$
\frac{(y-k)^2}{a^2}
+
\frac{(x-h)^2}{b^2}
= 1
\\ \\ or \\ \\
\frac{(x-h)^2}{b^2}
+
\frac{(y-k)^2}{a^2}
= 1
$$

### **Ellipse Coordinates**

- **Horizontal Ellipse Coordinates**
    | | |
    | --- | --- |
    | $C(h, k)$ | Center |
    | $F(h \pm c, k)$ | Foci |
    | $MV(h \pm a, k)$ | Major Verticies |
    | $mV(h, k \pm b)$ | Minor Verticies |

- **Vertical Ellipse Coordinates**
    | | |
    | --- | --- |
    | $C(h, k)$ | Center |
    | $F(h, k \pm c)$ | Foci |
    | $MV(h, k \pm a)$ | Major Verticies |
    | $mV(h \pm b, k)$ | Minor Verticies |

**Note:** In the two tables $a$ is the largest
denominator, while $b$ is the smaller one.

### **Ellipse : Converting General form to Standard form**

1. Arrange liked terms
2. take-out the coefficients of the highest degree term of the polynomials if there is any: example $4x^2+16x$ into $4(x^2 + 4x)$, just add parentheses if there is no coefficients
3. complete the squares of the inner trinomials $x^2+bx+c$ using the formula $c = \left( \dfrac{b}{2} \right)^2$, and don't forget to add the product of the resulting $c$ and the outer coefficient to the left side of the equation.
4. factor-out the resulting trinomials
5. solve the right side constant and divide the left and right side of the equation with it.
6. reduce the fraction in the left side of the equation.

**Example**:

Given $12y^2-4x^2+72y+16x+44=0$, reduce it to standard form ellipse equation.

1. Arrange liked terms

    $-4x^2+16x+12y^2+72y=-44$

    (optional: since I like to work with a positive $x^2$, I will multiple both sides to -1 to flip the signs, note that the resulting equation will still be the same)

    $4x^2-16x-12y^2-72y=44$

2. take out the coefficients, for the 2nd terms $16/4 = 4$ and $72/12 = 6$

    $4(x^2-4x+ c?)-12(y^2-6y+c?)=44$

3. complete the squares using $c = \left( \dfrac{b}{2} \right)^2$, here the $b$ 's are the coefficients of the 2nd terms of the trinomials being $-4x$ and $-6y$

    $c1=\left( \dfrac{-4}{2} \right)^2=4$

    $c2=\left( \dfrac{-6}{2} \right)^2=9$

    $4(x^2-4x+4)-12(y^2-6y+9)=44 + (4 \cdot 4) + (-12 \cdot 9)$

    $4(x^2-4x+4)-12(y^2-6y+9)=44 + 16 - 108$

    $4(x^2-4x+4)-12(y^2-6y+9)= -48$

4. factor-out the resulting trinomials

    $4(x-2)^2-12(y+3)^2= -48$

5. divide the resulting right side of the equation to both sides

    $\dfrac{4(x-2)^2}{-48}-\dfrac{12(y+3)^2}{-48} = \dfrac{-48}{-48}$

6. reduce the fractions

    $\dfrac{(x-2)^2}{-12}-\dfrac{(y+3)^2}{-4} = 1$

    $-\dfrac{(x-2)^2}{12} + \dfrac{(y+3)^2}{4} = 1$

    $\dfrac{(y+3)^2}{4} - \dfrac{(x-2)^2}{12} = 1$