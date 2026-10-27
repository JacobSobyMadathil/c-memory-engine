# C Data Structures & Memory Management Engine

An extensive collection of low-level algorithms, dynamic memory implementations, dynamic data structures, and spatial algorithms implemented strictly in standard C.

## 📌 Project Overview
This repository contains low-level C programming routines designed with direct memory access, pointer arithmetic, custom allocation strategies, and foundational data structures.

## 🛠️ Key Technical Highlights
- **Dynamic Memory Control:** Hands-on usage of `malloc`, `calloc`, `realloc`, dynamic buffer expansions, and boundary checks.
- **Pointer Arithmetic:** Elimination of standard array indexing in favor of direct address offset manipulations.
- **Data Structures:** Custom implementations of Linked Lists, Doubly Linked Lists, Priority Queue nodes, and dynamic structs.
- **Matrix Algorithms:** Spatial filtering, neighbor accumulations, multi-pass 2D maximum pooling, and 3D tensor reductions.

## 📁 Repository Structure

### 1. `01_Dynamic_Memory/`
Focuses on dynamic array allocations, buffer reallocations, and pointer-based operations.
- `array_stats.c` - Array statistics using raw pointer offsets.
- `deduplicate.c` - Two-pointer in-place deduplication.
- `array_insert_delete.c` - Dynamic element insertion and deletion via `realloc`.
- `array_interleave.c` - Memory resizing with adjacent element interleaving.
- `array_rotation.c` - In-place rotation via sub-array reversal.
- `array_transformer.c` - Modulo conditional array transformation.
- `dynamic_realloc.c` - `realloc` array expansion.

### 2. `02_String_Manipulation/`
String handling using dynamic buffers, custom string logic, and character manipulation.
- `frequency_counter.c` - ASCII character occurrence counter.
- `palindrome_reverse.c` - Pointer-based string reversal and palindrome validation.
- `string_array_sort.c` - Alphabetical sorting of dynamically allocated 2D string buffers.
- `length_sort_strings.c` - Length-based string sorting algorithms.
- `word_replace.c` - Dynamic string array lookup and target replacement.
- `word_append_search.c` - 2D dynamic string lookup & append.

### 3. `03_Data_Structures/`
Custom node-based data structures constructed via low-level memory allocation.
- `priority_queue_list.c` - Dynamic priority queue with node insertion, search, and deletion.
- `doubly_linked_list.c` - Bi-directional traversal on custom doubly linked structures.
- `list_split_merge.c` - Alternate node splitting and multi-list merged sorting.
- `list_merge.c` - Linked list merging skeleton.

### 4. `04_Matrix_Algorithms/`
Low-level 2D/3D matrix allocations and spatial filtering algorithms.
- `maximum_filter.c` - Multi-pass 2D spatial maximum filter (Max Pooling).
- `neighbor_sum_grid.c` - Matrix transformation based on 4-neighbor boundary sums.
- `3d_tensor_reduction.c` - 3D memory array allocation and plane reduction operations.

### 5. `05_Structures_Applications/`
Applications utilizing dynamic `struct` arrays, pointer swapping, and evaluation engines.
- `student_records.c` - Dynamic struct array sorting and pointer search.
- `delivery_agent_eval.c` - Multi-criteria scoring engine with structural evaluation.
- `inventory_realloc.c` - Dynamic inventory tracking with memory resizing.
- `contact_directory.c` - Struct reallocation directory.
- `inventory_system.c` - Inventory tracking across branches.
- `min_max_swap.c` - Pointer swapping of extremes.
- `pos_neg_pointer_swap.c` - Smallest positive/largest negative swap.
## 💻 How to Compile and Run
Compile any module using `gcc` (C99 standard or higher):

```bash
# Example: Compiling the Maximum Pooling Filter
gcc -O2 04_Matrix_Algorithms/maximum_filter.c -o max_filter

# Run executable
./max_filter
