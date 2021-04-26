Dear Mike, 
Here is the description of the game which I thought would help in understanding some of the thoughts I went as I developed the game.

This game is not too different from the one I submitted for the idea submission long ago. I have made a few changes here and there to allow
myself to expand but also to restrict what I need to do to fully develop the game. I have still used all of the required C++ techniques and
have fit in as many implementations where I saw fit to use them.

I had some struggles finishing this project as I could not find the cause of some memory leaks and could not figure out how to get rid 
of them. I had many issues with figuring out where they were as well as even though I followed the MSDN documentation on the memory 
leak lines I had some issues with unloaded debug libraries which made it difficult to find the source of the memory leaks. 

There was another issue in which I could not figure out how to delay the change of texts in between the battle to alert the user to every
action which has occured as it would skip over when the opponent defended the user's attacks. There were some issues with the card types
but I managed to fix them such that specific ard types could not fight each other. Finally I was able to make the user save file change
and dynamically fill itself as users earnt new cards. 

The various save files can be found inside the folder saveData which contains the users, cards and special abilities files and those allow
for much more easily customizing and adding new cards, users or special abilities than hard coding them in. 

To start up the application the source file should be run and that should open up the main menu to get access to the rest of the windows. 
The rest from their is explained through various comments in the files of each window or any of the classes behind them. The instructions 
given to the user are as clear as I could think them to be and hopefully it is easy to understand and walk through. Please let me know if
you have any further questions about the application or any parts of the code. 

And my apologies for sending this late, I suffered an injury to my hand which prevented me from typing without pain so I had to take an
extra week till it healed. 

Best Regards,
Mazen Omar 
29042121