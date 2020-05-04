# Lecture 10-2: INHERITANCE AND GENERALIZATION

a.k.a. *TWO FORMS OF POLYMORPHISM*

This folder contains my slides for Lecture 10-2 as PDF, as well as my
inheritance example, a `class Account` and some derived classes, these
within the `samples` folder. Below are my notes describing the slides
that present the `Account` hierarchy. I also provide a `Shape` hierarchy
in the `samples` folder.

There is also an example of a C++ *template class*. This is defined in
`samples/Stck_T.hh` and used by a slightly modified `dc.cc` client.
The code gives a parameterized `class Stck<T>` that can be defined
for any type `T`.

Templates form the backbone of the C++ *Standard Template Library*
or *STL*, as you might imagine from the name. We'll start looking 
at this library in Lecture 10-3.


## Video Links

`Slide 01` [Part 01. Inheritance: Account Hierarchy](https://ensemble.reed.edu/Watch/r9TNj8s4) *15m00s*  
`Slide 26` [Part 02. Virtual Methods](https://ensemble.reed.edu/Watch/f9RFg46Y) *13m45s*  
`Slide 43` [Part 03. Shape Example](https://ensemble.reed.edu/Watch/z4KHd6a9) *03m30s*  
`Slide 57` [Part 04. Polymorphism](https://ensemble.reed.edu/Watch/g2WLy47A) *06m00s*  
`Slide 62` [Part 05. Templates](https://ensemble.reed.edu/Watch/Wp2y6J8S) *14m15s*  
`Slide 70` [Part 06. Template Compilation Question](https://ensemble.reed.edu/Watch/Gf6e4NHi) *02m30s*  

---

### Inheritance in C++

Below we give an example of a *class hierarchy* written in C++.
There is a *base class* named `Account` that three other classes
*derive* from, one indirectly. Thus they each inherit the 
attributes and methods of that class, and some extend their
definition with additional attributes. The full class hierarchy
is suggested by the diagram below:

         Account
         /     \
    Savings   Checking
                 \
               Promotional

Each represents a kind of banking account. All have a name,
an account number, a balance, and accrue interest at a certain
monthly rate and (maybe) only under certain conditions.

Here is the code:  
• [Account.hh](samples/Account.hh)  
• [Account.cc](samples/Account.cc)  
• [test_acct.cc](samples/test_acct.cc)  
The last file defines a `main` that is a client of the account
classes. In that code you can tweak the declaration of the
variable `cAcct` so that it uses `Promotional` rather than 
`Checking`.

---

### Notes on the above

**protected**  
The base `Account` class declares the object attributes
`protected` so that the deriving classes can access them directly in
their methods. Were they instead marked as `private`, then those
derived classes would have to rely on the `public` interface (e.g. the
"getter" `getBalance`, etc.), or any `protected` interface methods,
were there some, to access or modify those attributes.

Probably the right thing to do is to define `public` *getter methods*
and either `protected` or `public` *setter methods*, if appropriate,
rather than make the attributes accessible to derived classes.
Here, I just wanted to keep things simple, and illustrate how
`protected` works. 

**constructors**  
They each define their own constructors. In the case
of the derived classes, the constructors use the constructor of the
class they derive directly from, and that occurs within the 
initializer section of the constructor. For example, the 
`Checking` constructor makes use of the `Account` constructor
to initialize those derived attributes, but then sets its own
`level` attribute. If the use of the `Account` constructor
not made explicit in the initializer section, then the
default constructor for `Account` would be implicitly
called before the code for the `Checking` constructor
runs. Something has to do the work of initializing the
base class components of `Checking` objects!

**virtual**  
There is an interesting quirk to the default behavior of C++
when it "dispatches a message" to a receiving object. For
example, consider the example code below. Assume that  `class B` 
derives from `class A` and that code for the methods 
`A::m` and `B::m` are defined. 
   
    A *a = new B();
    a->m(x);

In the above, we are sending the message `m` to the 
receiving object referenced by `a` with the argument
`x`.  From your experience with other languages, it would
be reasonable to assume that the code of the method `B::m` 
is "dispatched" to handle `m`. Instead a C++ programmer
can control this dispatch. Depending on what they want,
either the code for `A::m` will be invoked or the code
for `B::m` will be invoked. Which happens is based
on the declaration of `m` in A.

Suppose the declarations something like so:

    class A {
        ...
        void m(...);
        ...
    }

    class B : public A {
        ...
        void m(...);
        ...
    }

Here, class `A` declares the method `m` **without using the keyword**
`virtual`, and so the programmer is indicating that *static dispatch*
should be used.  In that case, even though `a` points to a `B`
instance, C++ compiles the client code so that it runs the code for
the method `A::m`. That is, it uses the type of the variable `a` to
figure out what code to run, and it does this at compile time.

Note that this is not typical behavior within the vast family of
object-oriented languages. The typical behavior is *dynamic dispatch*,
where the method code to be run is determined by the actual
contents/type of the object receiving the message. In C++, a
programmer has to be explicit about their desire for dynamic dispatch
behavior for a message's send. They do so by putting `virtual` in
front of the base declaration of that method in the class declaration.
So we will normally declare the method `m` this way in class `A`:


    class A {
        ...
        virtual void m(...);
        ...
    }

This makes our C++ code to mimic the behavior of other object-oriented
languages. We are, at the moment, less concerned about performance
than some C++ programmers are. For this reason, we mark all our
methods as `virtual` in the class where they are introduced. When a
deriving class overrides the definition of a virtual method, dynamic
dispatch will get used to handle receipt of that message. The object's
method will get used, rather than the method indicated by that
object variable's type.

I recommend that you mark all methods, when introduced into a
hierarchy, as `virtual` until you learn what the other style
means. Most modern programmers intend for dispatch to be dynamic
rather than static.

---




