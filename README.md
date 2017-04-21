# firstCppGame
3rd year final semester project using cpp &amp; unreal engine 4

# Introduction
### (i) Project Summary
In this project, I aim to successfully build a top down single player arcade style dungeon crawler game using Visual Studio to write C++ code, & Unreal Engine 4. A dungeon crawler by definition is  a type of scenario in fantasy role-playing games (RPG’s)  in which a hero navigates a labyrinthine environment or dungeon, battling various monsters, and looting any treasure they may find. By the end of the project I hope to have the environment procedurally generating, this would save time having to build all environments manually. 

### (ii) Expected Problems
As I have only a basic knowledge of C++ and am completely unfamiliar with the Unreal Engine 4  I expect to have some problems whilst trying to learn how to correctly compose, write, build, & develop using these tools. It will take some time to adjust to how C++ is written and to reserch how to correctly compose a C++ project.
Adjusting to the unreal engine will take a little bit of time.

Procedural generation of the world is a complex, & large undertaking, which will more than likely require more than 3 months to build. 

### (iii) Anticipated achievements
By the end of this project I hope to have a functioning, fun, game. I also hope to have a better understanding of C++, & why it is an industry standard for games development, & finally knowledge of how to develop using an industry standard game engine: Unreal Engine 4.

# Concept, Rules & Requirements
### (i) Concept 
In the game, you the user will play as our unnamed hero. You will attempt to navigate the unnamed hero out of the dungeon safely while battling many foes, solving puzzles, and finding loot on your travels. Once you finish the game you will be given a score which is based off how many foes you have defeated, collected items, puzzles solved, and completion time. You may then choose to re-play the game if you so wish. I hope to implement save points or checkpoints at which players can come back and pick up where they left off.

### (ii)Rules 
    1 The user must survive to progress
    2 The user will build a score 

### (iii) Requirements
    1 The user should be able to control the protagonist (movement, combat, interaction with environment).
    2 An environment in which the user can traverse
    3 Roaming enemies / enemy AI

## Technologies used

1. Unreal Engine 4
2. Visual Studio
3. C++

#### About Unreal Engine 4

> The Unreal Engine is a game engine developed by Epic Games, first showcased in the 1998 first-person shooter game Unreal. Although primarily developed for first-person shooters, it has been successfully used in a variety of other genres, including stealth, MMORPGs, and other RPGs. With its code written in C++, the Unreal Engine features a high degree of portability and is a tool used by many game developers today.

> It has been awarded by Guinness World Records as "the most successful video game engine".

For further information about about Unreal Engine see the following:
[Unreal Homepage](https://www.unrealengine.com/)
[Unreal Wiki](https://en.wikipedia.org/wiki/Unreal_Engine)

#### About Visual Studio

> Microsoft Visual Studio is an integrated development environment (IDE) developed by Microsoft. Used to develop computer programs for Microsoft Windows, as well as web sites, web apps, web services, mobile apps, & more. It can produce both native code and managed code.

> Visual Studio supports different programming languages and allows the code editor and debugger to support numerous programming languages. Built-in languages include C, C++ and C++/CLI, VB.NET, C#, F#, & TypeScript. Support for other languages such as Python, Ruby, Node.js, & M among others is available via language services installed separately. It also supports XML/XSLT, HTML/XHTML, JavaScript and CSS. 

For further information about Visual Studio see the following:
[Visual Studio homepage](https://www.visualstudio.com/)
[Visual Studio Wiki](https://en.wikipedia.org/wiki/Microsoft_Visual_Studio)

#### About C++

> C++ is a general-purpose programming language. It has imperative, object-oriented and generic programming features, while also providing facilities for low-level memory manipulation.

> It was designed with a bias toward system programming and embedded, resource-constrained and large systems, with performance, efficiency and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, servers, and performance-critical applications. C++ is a compiled language, with implementations of it available on many platforms. Many vendors provide C++ compilers, including the Free Software Foundation, Microsoft, Intel, and IBM.

> C++ is standardized by the International Organization for Standardization (ISO), with the latest standard version ratified and published by ISO in December 2014 as ISO/IEC 14882:2014. The C++ programming language was initially standardized in 1998 as ISO/IEC 14882:1998, which was then amended by the C++03, ISO/IEC 14882:2003, standard. The current C++14 standard supersedes these and C++11, with new features and an enlarged standard library. Before the initial standardization in 1998, C++ was developed by Bjarne Stroustrup at Bell Labs since 1979, as an extension of the C language as he wanted an efficient and flexible language similar to C, which also provided high-level features for program organization. The C++17 standard is due in July 2017, with the draft largely implemented by some compilers already, and C++20 is the next planned standard thereafter.

> Many other programming languages have been influenced by C++, including C#, D, Java, and newer versions of C.

For further information about C++ see the following:
[cplusplus Website](http://www.cplusplus.com/)
[C++ Wiki](https://en.wikipedia.org/wiki/C%2B%2B)

#### Why did I use the above?

I decided to use the Unreal Engine 4 (UE4) as my main development environment as it is free, & a powerful tool for building / developing games.
I wanted to build a 3d game and learn some c++ while I was at it, while researching engines I came to the conclusion that UE4 would be the best tool for the job.
With no previous experience or knowledge using UE4, or C++ I knew that development would be a challenge. 
The reason I wanted to learn C++, is that it is widely used across different studios for development of games, applications, serverside logic, and much more. 
I felt that it is important that I at the very least learn the fundamentals of the language as it differs to the languages I currently know such as Java, but by applying the theoretical knowledge of what I know about object oriented programming, I would be able to learn the fundamentals fast and with relative ease.. Or so I thought.

## User Guide

##### Controls

To play you can use either a controller (recommended) or your keyboard and mouse. See the control schema below: 
Controller:
![controller](http://imgur.com/qbzjYVV.png)

Keyboard & mouse:
![keyboardmouse](http://imgur.com/kfFuPPl.png)

##### Rules

The aim of the game is to survive as long as possible & build up a high score. If you come into contact with an enemy you will lose health.
If your health drops to 0 you will die & be respawned.

## Development methodology

During development I often reffered to the Unreal Documentation for coding standards / procedures. The game was developed with a loosely coupled object oriented design in mind.

For example: Abstraction & inheritance were used when possible, the player & enemy are abstracted from the base character class & also inherit iDamagable. These contain common traits that span across both of these types of Actors (Player & Enemy). 



## Known Bugs

1. Minor - door does not recognise player, able to walk through / collision detection not working as expected
2. Minor - in some cases the player controller does not get disabled after death

## Conclusion

Before starting the project I wanted to build something that would challenge me, force me out of my comfort zone, & allow me to learn something new.

I first decided to build the game in UE4, I then began research on both c++ & UE4. I had to understand the fundamentals of c++, how it works, how it differs to what I know already, & best practices when writing c++. I spent roughly 2 weeks researching and prototyping in c++ at the beginning. I then turned my attention to UE4, reading their API’s which for c++ & general usage of the engine, I did this for about 2 weeks before I began my project. At this point I felt pretty comfortable to go ahead.

What I learned about UE4 is that I wouldn’t have to rely heavily on c++ to do everything for me which was great. Granted I did want to learn the language, but c++ is a very complex language that involves a higher learning curve than usual, outside of the fundamentals I knew nothing about it. In UE4 they have a scripting method called Blueprints, these are essentially graph based algorithms which allow you to do the same as you would in c++ without having to be a master of the language. I quickly learned that automating something in blueprint was faster than c++, the reason being that Epic’s documentation is far better for blueprint than c++.

Through out the development I ran into very few issues that I could not solve within’ a day or two.. until I began building an algorithm which would procedurally build the world for me. At this point I took a step back began prototyping and researching again, I did this for about 3 weeks and successfully built a simple algorithm in c++ which would build rooms and plot them within’ a defined space. 

When it came to putting this into Unreal, I ran into bigger issues. It was overly complex trying to draw objects from a c++ script into the world, & unfortunately the documentation was not descriptive enough to be of any use…. So from there I started building an algorithm to do this in blueprint and for the most part there was instant progression. Objects were being drawn to the world with collision boxes, textures, and so on so forth, the only issue is, to draw something in console it was simple, store it in a 2d array and print it to screen… It’s not that simple in UE4.. I spent about 3 weeks going back and forth doing research and testing different ways to procedurally generate the world, until I finally figured that there would be no way I’d be able to write this algorithm, finish all other game mechanics, and do my other projects thats submission dates were drawing closer, so I dropped development on the procedural world building algortihm.

If I we’re to do anything differently when I next start a project in UE4, I would script more in c++, while I do find the blueprint graph based algorithm useful, it proprietary and to the best of my knowledge is not used in elsewhere, but with that knowledge i can now draw out algorithms to gain further understanding of how they work.

Overall I feel like this has been more of a learning experience rather than building something that’s ready for market. This game is not ready for market.  

#### Recommendations & References

If I am to continue this project, more research & prototyping of c++ is required:

| Topic | Reference |
| --- | --- |
| Unreal API's | [Unreal Documentation](https://docs.unrealengine.com/latest/INT/index.html) |
| C++ programming | [c++ training](https://www.tutorialspoint.com/cplusplus/) |
| c++ best practices | [c++ best practices](https://isocpp.org/wiki/faq/coding-standards) |

To be able to procedurally generate interconnected rooms / a world is a bigger task than 2 - 3 months wortk of work.

| Topic | Reference |
| --- | --- |
| Procedural generation | [Procedural generation](https://en.wikipedia.org/wiki/Procedural_generation) |
| Theory of procedural programming | [Procedural theory](https://en.wikipedia.org/wiki/Procedural_programming) |

Deeper knowledge of game development and design is also required:

| Topic | Reference |
| --- | --- |
| Game Design | [Game Design Theory & Practice](https://gamifique.files.wordpress.com/2011/11/5-game-design-theory-and-practice.pdf) |
| Game Development | [Beginning Cpp through game programming](https://tfetimes.com/wp-content/uploads/2015/04/Beginning_Cpp_Through_Game_Programming.pdf) |


Daniel.
