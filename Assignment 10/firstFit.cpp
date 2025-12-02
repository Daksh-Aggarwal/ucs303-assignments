void firstFit(vector<int> &blocks, int req) {
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i] >= req) {         // block found
            blocks[i] -= req;           // allocate memory by reducing size
            cout << "Allocated " << req << " in Block " << i << " (First Fit)\n";
            return;
        }
    }

    cout << "Allocation failed: no block large enough.\n";
}
