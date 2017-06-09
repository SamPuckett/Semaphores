# Semaphores
Food Passing Synchronization

This C++ program highlights the uses of Semaphores and thread synchonization.

A Server, Diners, and a Busser are all synchonized to minimize busy-wait and make more efficient use of CPU cycles while making sure deadlock does not occur.

Server: Places plates on the first trivet if its empty.

Diner: Gets food from trivet left of them, and moves the trivet to their right for the next diner or the busser.

Busser: Removes the plate from the last trivet on the table once all the diners have gotten their share of the food.
