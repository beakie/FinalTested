/*

 1) Do Hsv to Rgb and vice versa
 2) Migrate tri and quad pixel to vector?
 3) Do matrix based color model converters
 4) Write color model pixelconv for all models which use matrix multiplication
 5) Change pixel to color for colormodel stuff?
 6) Create color convert functions (and call them from the pixel convert code?)
 7) Make UnitInterval class instead of float... should do a mod 1 on assignment operator
 8) Change colormap stuff to use vector3
 9) Rename colormap linearcolormap?
10) Maybe make a unit interval wrapper class that could be put around a basic data float variable
11) Add a non linear color map. Add the color map variable to a new NonLinearColorMap class. Write a new TriColorMapNonLinearPixelConv (and quad)
12) Do some arduino tests
13) Does the first colormapper code really need bounds? Bounds are only needed with floats (?) will i be doing this with floats? Instead make a seperate converter just for floats. Will make c/m faster for non float.
14) Migrate list Items stuff into small methods like image does?
15) Should the color stuff of picture actually be in common? .NET keeps it in system.drawing... do i?
16) Make sure vector stuff is finished and tested. crossproduct of vector4 needs working out, add const, generally check its all good.
17) Default all maths classes to float, where appropriate.
18) If boredom kicks in, have a go at trying to get .NET to implement this code. Wrappers n stuff?
19) Vector norm
20) Tuple operators
21) Static matrix functions. Look at end of Matrix2 for the list.
22) Matrix transformation builders

*/
