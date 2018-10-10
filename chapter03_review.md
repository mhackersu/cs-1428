## Chapter 1
## Chapter 2
## Chapter 3
### Hierarchy of Data Types
- Coercion
- Promotion
- Demotion
#### Type Casting
```static_cast<Data Type>(Value)```

- For Example (To find the class avgerage):
```
int numofstudents, totalpoints;
double avgscore = static_cast<double>(totalpoints) / numofstudents;
```

#### Overflow and Underflow
- Overflow - When assigning a value that is too large (may display as a negative).
- Underflow - When assigning a value that is too close to zero to store as var.

#### Named Constants
- Make program code more readable.
```
const double TAX_RATE = 0.0775;
salesTax = purchasePrice * TAX_RATE;
```
- Improve accuracy and simplify program maintenance.
```
const double TAX_RATE = 0.0775;
```
