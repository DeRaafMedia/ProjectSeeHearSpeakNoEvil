ProjectSeeHearSpeakNoEvil
=========================

This project was writen more than 6 years ago as an exploration of openCV and what I could do with it in the Processing.org enviroment.

Since I upgraded to Yosemite a lot of old Processing sketches broke, rather than fixing the problem I wanted to do a complete rewrite (JAVA is dead?).

This project takes a live videofeed (this was writen with a built-in Apple FaceTime HD camera as source). Recongnizes the face(s) in it, and asigns a 'seeNoEvil', 'HearNoEvil' or 'SpeakNoEvil' mask to a face it finds. The mask is persistent to a face until the face disappears. The masks are assigned semi random.

This project needed to be written specifically as a 32 bit app (so no universal biaries as of yet!).