# cse1320
cse1320/
├── main.c # Main program
├── data.c # Event struct and file handling
├── organizer.c # Add/Delete/Edit events
├── viewer.c # Display/Search events
├── interaction.c # Menu and RSVP
└── events.txt # Persistent storage

Run these 2 command:
gcc main.c data.c organizer.c viewer.c interaction.c -o communiknot
./communiknot
