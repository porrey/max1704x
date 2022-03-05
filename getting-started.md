[**Home**](https://porrey.github.io/max1704x) -
**Getting Started** -
[**Constructor**](https://porrey.github.io/max1704x/constructor) -
[**Initialization**](https://porrey.github.io/max1704x/initialization) -
[**Functions**](https://porrey.github.io/max1704x/functions)
# Getting Started
## Adding the Library
In the Arduino IDE, click the **Sketch** menu and choose **Include Library** and then **Manage Libraries...**. In the search box type **MAX1704X**. Highlight the library and clikc the **Install** button.
## Include the Library
Using the library requires adding a the library header file to your sketch.

If you are using the MAX17043 (one cell battery) device, then add the line shonw below to the top of your sketch.

`#include "MAX17043.h"`

[**Next Step**](https://porrey.github.io/max1704x/initialization)

If you are using the MAX17044 (two cell battery) device, then add the line shonw below to the top of your sketch.

`#include "MAX17044.h"`

[**Next Step**](https://porrey.github.io/max1704x/initialization)

If you are wish to initalize the library yourself, then add the line shonw below to the top of your sketch.

`#include "MAX1704X.h"`

Additionally, you will need to call the constructor on the class to create an instance.

[**Next Step**](https://porrey.github.io/max1704x/constructor)