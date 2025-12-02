void worstFit(vector<int> &blocks, int req) {
    int index = -1;

    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i] >= req) {
            if (index == -1 || blocks[i] > blocks[index]) // ONLY DIFFERENCE BETWEEN BEST FIT AND WORST FIT
                index = i;  // choose biggest block
        }
    }

    if (index != -1) {
        blocks[index] -= req;
        cout << "Allocated " << req << " in Block " << index << " (Worst Fit)\n";
    } else {
        cout << "Allocation failed: no block large enough.\n";
    }
}
