# Communication protocol
- User to user
  - DONE: Communication nodes and messages
  - DONE: Time simulation & proper display in logs
    - DONE: exact clock for World, potentially drifting clocks for nodes
    - DONE: Logger including time
    - DONE: Indent in and out
  - DONE: Exchanging-interval and sleeping-interval to reduce power consumption
    - DONE: Example: 5 seconds of exchange, then 10 of sleep
    - DONE: When a node speaks the other should listen!
      - Talking time-slice during exchanging-interval
        - Example: during the 5 seconds, 10 talking time slices of 500 ms each
        - DONE: Cannot know who is around when booting => Start with round-robin algorithm depending on MAC ID: should reduce collision probability
  - Find talk slot automatically 
    - DONE: By listening to other nodes, chose a talking time slice which is different from one of the surrounding nodes (meaning: hop <= 2 for example)
    - v2, improvements
      - Have the minimum number of nodes to change timeslot
      - What about the Terminals that can move around? Different range for Terminals & Repeaters? Or fixed slot for Terminals <> from Repeaters?
  - Signal collision when two nodes talk at the same time in the same area
  - Time sync and drift of communication nodes
    - How many times per day?
      - By default when a message is transmitted
      - When no message is transmitted?
    - To be also used to determine the talking time-slice: sync will start before sending messages
    - Who has the authority to send time syncs? Is this needed?
    - Syncing with official time is probably not an issue as long as all nodes are in sync
    - However, if a user sees the time, it will be a problem => do not show this time
    - Should we use the NTP protocol? https://fr.wikipedia.org/wiki/Network_Time_Protocol
- Group to group
- Network configuration: reconfigure all nodes
- Firmware update

# To be decided
- Intégrer les critères de priorité etc. de manière à ce que les répéteurs renvoient plus souvent, ou qu'il y ait une demande d'acknowledge

# Security
- Specifications!
  - User security
    - Create user certificate
    - Create new
  - Groups security

# Embedded
