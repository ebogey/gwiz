// ***************************************************************************
// FastaIndex.h (c) 2010 Erik Garrison <erik.garrison@bc.edu>
// Marth Lab, Department of Biology, Boston College
// All rights reserved.
// ---------------------------------------------------------------------------
// Last modified: 5 February 2010 (EG)
// ---------------------------------------------------------------------------

#ifndef _FASTA_H
#define _FASTA_H

#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <algorithm>
#include "LargeFileSupport.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include "split.h"
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "Region.h"

using namespace std;

namespace fastahack
{

class FastaIndexEntry {
    friend ostream& operator<<(ostream& output, const FastaIndexEntry& e);
    public:
        FastaIndexEntry(string name, int length, long long offset, int line_blen, int line_len);
        FastaIndexEntry(void);
        ~FastaIndexEntry(void);
        string name;  // sequence name
        int length;  // length of sequence
        long long offset;  // bytes offset of sequence from start of file
        int line_blen;  // line length in bytes, sequence characters
        int line_len;  // line length including newline
        void clear(void);
};

class FastaIndex : public map<string, FastaIndexEntry> {
    friend ostream& operator<<(ostream& output, FastaIndex& i);
    public:
        FastaIndex(void);
        ~FastaIndex(void);
        vector<string> sequenceNames;
        map<string, unsigned int> sequenceID;
        void indexReference(string refName);
        void readIndexFile(string fname);
        void writeIndexFile(string fname);
        ifstream indexFile;
        FastaIndexEntry entry(string key);
        void flushEntryToIndex(FastaIndexEntry& entry);
        string indexFileExtension(void);
};

class FastaReference {
    public:
        void open(string reffilename);
        bool usingmmap;
        string filename;
        FastaReference(void) : usingmmap(false) { }
        ~FastaReference(void);
        FILE* file;
        void* filemm;
        size_t filesize;
        FastaIndex* index;
        vector<FastaIndexEntry> findSequencesStartingWith(string seqnameStart);
        string getSequence(string seqname);
        // potentially useful for performance, investigate
        // void getSequence(string seqname, string& sequence);
        string getSubSequence(string seqname, int start, int length);
        string getTargetSubSequence(FastaRegion& target);
        string sequenceNameStartingWith(string seqnameStart);
        unsigned int getSequenceID(string seqname);
        long unsigned int sequenceLength(string seqname);
};
} // end namespace fastahack
#endif
