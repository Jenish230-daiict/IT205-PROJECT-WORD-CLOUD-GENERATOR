# IT205-Project-P5
<br>
<h2>Title : Word Cloud Generator </h2>
<br>
<h3>Group Name : Binary Bots</h3>
<br>
<p>Members of Group : </p>
<table>
    <tr>
        <th>SR. NO</th>
        <th>ID</th>
        <th>NAME</th>
        <th>CONTRIBUTION</th>
    </tr>
    <tr>
        <td>1</td>
        <td>202301172</td>
        <td>MACWAN JENISH DENISH</td>
        <td>FUNCTION TO READ TXT FILES AND MAKE GUI</td>
    </tr>
    <tr>
         <td>2</td>
        <td>202301192</td>
        <td>PATEL HARSH NARESHBHAI</td>
         <td>FUNCTION TO READ CPP FILES AND DOCUMENTATION</td>
    </tr>
    <tr>
         <td>3</td>
        <td>202301064</td>
        <td>URVESH DABHI</td>
        <td>MAIN FUNCTION AND FUNCTION TO READ PDF FILES</td>
    </tr>
    <tr>
         <td>4</td>
        <td>202301132</td>
        <td>SWAR PATEL</td>
        <td>LIST CLASS IMPLIMANTATION AND DEBUGGING</td>
    </tr>
</table>

### **Word Cloud Generator using Linked List**

This project implements a **Word Cloud Generator** using a **singly linked list** as the primary data structure. The program reads a text input, processes it to extract and count unique words, and then displays a visual representation of the most frequent words in the form of a word cloud.

#### **Key Features:**

* **Text Parsing:** The input text is tokenized into individual words, removing punctuation and ignoring case sensitivity.
* **Linked List Storage:** Each unique word is stored as a node in a linked list. Each node contains:

  * The word
  * The frequency count of that word
  * A pointer to the next word node
* **Dynamic Frequency Tracking:** If a word already exists in the list, its frequency count is incremented. If it’s new, a new node is appended to the list.
* **Visualization:** The final word cloud is either printed in text format with increasing font sizes based on frequency or exported to a graphical format (if integrated with a GUI or external visualization library).

#### **Advantages of Using Linked List:**

* Dynamic memory usage: Easily handles texts of varying sizes.
* Efficient insertion of new unique words without resizing or shifting elements.
* Simple to implement and manipulate for educational purposes.

#### **Limitations:**

* Slower search compared to hash maps or balanced trees.
* Less efficient for large datasets due to linear traversal.

#### **Applications:**

* Educational tools for understanding data structures.
* Basic text analysis tools.
* Backend for simple UI-based word cloud apps.
---

### **File Structure and Responsibilities**

The implementation of the Word Cloud Generator using a linked list is organized into **three main source files**:

* **`main.cpp`**
  This file serves as the **user interface** of the project. It handles user interaction, such as prompting the user to choose a text file for input. It acts as the entry point of the application.

* **`doc.cpp`**
  This file is responsible for the **core document processing functionality**. It:

  * Reads text content from the user-selected file.
  * Extracts individual words from the text.
  * Passes the extracted words to the linked list for insertion.

* **`list.cpp`**
  This is the **data structure core** of the project. It manages the **linked list of words** by:

  * Inserting each word as a node.
  * **Incrementing the frequency** of a word if it already exists in the list.
  * Providing the **`topK()`** function that returns the **top K most frequent words**, based on the user’s choice.
  * Also deletes the whole linked list after completion of the task.
* You can see example run in **Capstone Project.pdf**.
