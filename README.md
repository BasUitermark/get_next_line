<div align="center">

  <img src="assets/text-alignment.png" alt="logo" width="200" height="auto" />
  <h1>GET_NEXT_LINE</h1>
  
  <p>
    A dive into reading & parsing from a file descriptor.
  </p>
</div>
  
  # :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Roadmap](#compass-roadmap)
- [Contact](#handshake-contact)



## :star2: About the Project
A project made in accordance with the get_next_line project for the Codam Core Curriculum.
A short recreation of fgets and an introduction into malloc and free, file descriptors, parsing and using multiple files for a function. 
The first look into reading & parsing a set amount of bits from a file descriptor and eventually saving these to a char array.




### :dart: Features

Uses a limited amount of funtions with restrictions to read bits from a file descriptor.




## 	:toolbox: Getting Started

### :gear: Installation

As my [libft](https://github.com/BasUitermark/libft) project includes this function I recommend to go over to that project page.



## :eyes: Usage

```c
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

{
  int   fd;
  char  *str;
  
  fd = open("/relative_path", O_RDONLY)
  
  str = get_next_line(fd);
  printf("%s\n.", str);
  close(fd);
}
```



## :compass: Roadmap

Nothing to do here.


## :handshake: Contact

See my profile page for ways to contact me!
