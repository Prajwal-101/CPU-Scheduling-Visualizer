# CPU-Scheduling-Visualizer
This is a CPU scheduling algorithms visualizer which gives the comparison between various scheduling algorithms.

---------------------------------------------------------------------------------------------------------

WHY I CHOOSE TO DO IT?

When I started gaming a little bit, I was really curious about how these big games run in such tiny chips called CPU and how does the switching of processes happen while I play. eg-> I get a call while I play so how dose the OS know that it has to stop the current gaming process and run the incoming call process, how does two or more processes run so efficiently in the same CPU.
That’s when I came across the topic CPU SCHEDULING and by reading its methods, I was really curious to see it for myself that how this switching of process happens so I decided to build a project about this where I can implement and visualize these algorithms.

---------------------------------------------------------------------------------------------------------

WHAT IS IN THIS PROJECT?

It is a an CPU visualization tool which helps us to understand the concepts of Process Management where we can see how the diffrent algorithms works inside the CPU and we visiualize it using Gant Chart which is a time series chart starting from 0 seconds.

Here the user can study the inbuilt processe or he can also create his own processes and visiualize it using the Gant Chart. We have used both Preemptive as well as Non-Preemptive algorithms. The Gant Chart shows us how the processes gets scheduled one after another inside the CPU and using this Gant chart we can find many important properties of a process such as: 
1. Throughput
2. Arrival Time (AI)
3. Burst Time (XI)
4. Completion Time (CT)
5. Turn Around Time (TAT)
6. Response Time (RT)
7. Avg. Turn Around Time (Avg. TAT)

The Algorithms which are used in this are:
1. First Come First serve (FCFS)
2. Shortest Job First (SJF)
3. Shortest remaining Time First (SRTF)
4. Longest Remaining Time First (LRTF)
5. Priority Scheduling (PQ)
6. Round Robin (RR)

---------------------------------------------------------------------------------------------------------

WHAT I DID IN THIS PROJECT?

In the project code I provided, it appears that I have developed a C++ program for simulating and visualizing various CPU scheduling algorithms. Here's what I did in this project:

1. **User Interface Design**:
   - I designed a text-based user interface (UI) for the program. The UI displays menus, process information, and scheduling results in the console.

2. **Menu System**:
   - I created menu functions (`menu` and `panel`) that allow users to interact with the program by making choices. These choices include selecting scheduling algorithms and defining processes.

3. **Process Management**:
   - I implemented a `struct processes` to represent individual processes in the simulation. This structure includes attributes like ID, duration, priority, execution time, and waiting time.

4. **Process Input**:
   - I developed a function (`process_input`) to create and initialize processes based on user input. Users can specify the ID, duration, and priority of processes.

5. **List Processes**:
   - I implemented a function (`list_processes`) to display a list of processes, showing their IDs, priorities, and durations.

6. **Scheduling Algorithms**:
   - I created functions (`fcfs`, `sjf`, `sjf_simulator`, `priority_scheduler`, `priority_scheduler_simulator`, `robbin_round`) to simulate various CPU scheduling algorithms, including FCFS, SJF, Priority Scheduling, and Round Robin.
   - Some of these functions also include visual representations of the scheduling processes, helping users understand how these algorithms work.

7. **Main Program Logic**:
   - I structured the main function (`main`) to drive the program's overall flow.
   - It allows users to choose between predefined processes or enter new ones.
   - Depending on the user's choices, it calls the respective scheduling algorithm functions and displays their results.
   - The program continues to run until the user chooses to exit.
