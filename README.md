# Raytracer
Offline raytracing! Math! Oh My!

## Overview
This raytracer is being made from guidance with [The Ray Tracer Challenge](https://pragprog.com/titles/jbtracer/the-ray-tracer-challenge/)
from The Pragmatic Bookshelf. 

TL;DR the book gives you test cases to pass and some general concepts. No copy pasting code from a book or tutorial here.

This is my attempt at the project, along with any extra features I decide to add on in the future.

## Build Guide
This is my first attempt at using cmake since I wanted to use C++ for this particular project and wanted it to be crossplatform ish at best. but here's a quick run down tutorial of the set up:<br>
1. In the root of the repository where CMakeLists.txt is located, run `cmake -B<build directory location>` to create a build of the project. 
2. in the created build director run `make` to create the executable assuming you are running on a UNIX system. 
3. run `./main` in the terminal and boom you got yourself a program

Note: If you decide to generate a project for your favorite IDE, note that this project is not going to really trouble shoot anything outside of XCode for now since that is the system I am using.
