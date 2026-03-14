# CSE1320 - CommuniKnot Project

## Project Structure
```text
cse1320/
├── main.c          # Main program
├── data.c          # Event struct and file handling
├── organizer.c     # Add/Delete/Edit events
├── viewer.c        # Display/Search events
├── interaction.c   # Menu and RSVP
└── events.txt      # Persistent storage
```


## Compile and Run

Run these two commands in your terminal:

```bash
gcc main.c data.c organizer.c viewer.c interaction.c -o communiknot
./communiknot
```
