# Data Types

- booleans
  - true
  - false

- numbers
  - NaN
  - int
  - float
  - double
  - big int
  - big float
  - big double

- strings
  - template literal string
  - double quotes
  - single quotes

- Objects

- Arrays

- Map

- Set

- null
- undefined
- any
- unknow

- enum

- functions
  - fn

- Generic Types
  - fn<T>


## Arithmetic

```
add + me;
subtract - me;
multiply * me;
divide / me;
-negateMe;
```

## comparison and equality

```
less < than;
lessThan <= orEqual;
greater > than;
greaterThan >= orEqual;
```

- same type

```
1 == 2
"cat" != "dog"
```

- different type

```
311 == 'pi';
123 == '123';
```

## Logical operators

```
!true;  // false
!false; // true

true && false   // false (and)
true && true    // true  (and)

true || true    // true   (or)
true || false   // true   (or)
false || false  // false  (or)
```

## Precedence and grouping

```
var average = (min + max) / 2;
```

## Statements

```
println("Hello, world!");
println('Hello, world!');

"some expression";
'some expression';
```

### block

```
{
  println("First Statement!");
  println('Second Statement!');
}
```

## declaration var

```
var im_available = "here is my value";          // string
var im_available: string = "here is my value";  // string
var im_available;                               // undefined

var breakfast = 'breakfast';                    // breakfast
println(breakfast);

breakfast = "beignets"
println(breakfast);                             // beignets
```

## Control Flow

```
if (cond) {
  println('yes');
} elif () {
  println('else if yes');
} else {
  println('else no');
}

var a = 1;

while (a < 10) {
  println(a);
  a = a + 1;
  a++;
  a += 1;
}
```

Finaly for

```
for (var a = 0; a < 10; a++) {
  println(a);
}

for (var el of array) {
  println(el);
}
```

## Functions

```
fn sayHi();

fn sayHi(arg: string, args: string[], others: any[]) -> string {
  return 'str';
}

fn printSum(a, b) -> void {       // (a: any, b: any) fn |-> void
  println(a + b);
}

fn returnSum(a: int, b: int) -> int {
  return a + b;
}
```

## Closures

```
fn addPair(a, b) {
  return a + b;
}

fn identify(callback: fn<>) {
  return callback;
}

const another = identify(addPair)

println("result:", identify(addPair)(1, 2));
println('result v2:', another(1, 2));
```

```
fn outerFn() {
  fn localFn() {
    println('I\'m local!');
  }

  localFn();
}
```

return fun

```
fn returnFn() {
  var outside = 'outsize';

  fn inner() {
    println(outsize);
  }

  return inner;
}

var cb = returnFn();
cb();
```
## Ternary

var op = cond == true ? "str" : 123;

## Clases |-> POO (Object Oriented Programming)

```
interface BreakfastImp {
  x: int;
  y: float;
  booleano: bool;
  cook(): void;
}

class X {
  protected z: double;
}

class Breakfast implements BreakfastImp extends X {         // inheritance and implements
  private x: int;
  public booleano: bool;
  private y: float;
  
  cook() -> void {
    println('Eggs a-fryin\'!');
  }

  public Breakfast(x: int, y: float, z: double) {            // constructor
    super();

    this.x = x;
    this.y = y;
    this.z = z;
  }

  private sayHi() {}

  protected sayHo() {}
}
```

```
var breakfast: Breakfast = new Breakfast(3, 0.1, 20 as double);

println(breakfast);                           // Breakfast instance

breakfast.booleano = false;
```

## Functional Programming

```
const filt = (cond: int) => cond > 1;
const filtered = [].filter(filt);

// new array created with filter applied
println('filter:', filtered);
```

## Standard libraries

time? {
  clock
  Timer
  Date
  DateTime
}

filesystem::{fs}
path::{path}
