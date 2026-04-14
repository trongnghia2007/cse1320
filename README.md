# CSE1320 - CommuniKnot Project

## Project Structure

```text
/
├── main.c          # Main program, including event struct and file handling
├── organizer.c     # Add/Delete events
├── viewer.c        # Display/Search events
├── interaction.c   # RSVP and Menu interactions
└── events.txt      # Persistent storage
```

## Compile and Run

Run these two commands in your terminal:

```bash
gcc main.c organizer.c viewer.c interaction.c -o communiknot
./communiknot
```
