# dwe::calc_sci

It is a simple scientific calculator written in C++.  
It calculates equations in RPN (Reverse Polish Notation).
Eg.

equation: 2+2\*2  
RPN: 2 2 2 \* +  
result: 6  

2sin(90)+5!  
RPN: 2 90 sin * 5 ! +  
result: 122  

arcsin(arccos(arctan(tan(cos(sin(9))))))  
RPN: 9 sin cos tan arctan arccos arcsin  
result: 0.027419  

List of features and supported functions:  
    + - * ^ / ( ) ! |  
abs()  
sin()  
sind()  
sinh()  
asin()  
arcsin()  
cos()  
cosd()  
cosh()  
acos()  
arccos()  
tg()  
tan()  
tgh()  
tanh()  
atan()  
arctan()  
ctg()  
ctgh()  
actg()  
arcctg()  
ln()  
log()  
log2()  
log10()  
sqrt()  

# Licencing

dwe::calc_sci is released under the DWE-3 license. This is very similar to the BSD-3 license, but there are two slight changes. You must credit `dweorh` in a visible way, in both source code and binary form, so if your application makes use of this code, somewhere in there it must display that you have used it. `dweorh` makes these tools with the intention that they are fun and educational, and does so for no profit at all.

License (DWE-3)
Copyright 2021 dweorh.com

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

* Redistributions or derivations of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

* Redistributions or derivative works in binary form must reproduce the above copyright notice. This list of conditions and the following disclaimer must be reproduced in the documentation and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



This license is a fork of: https://github.com/OneLoneCoder/olcPixelGameEngine/wiki/Licencing, and rules how to apply that license are the same. Follow instructions for OLC-3 https://community.onelonecoder.com/2020/05/20/how-to-attribute-credit-cite-the-olcpixelgameengine/
