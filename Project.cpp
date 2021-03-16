#include <iostream> 
#include<vector>
using namespace std; 

bool searchIfPageAlreadyExistsInFrames(int key, vector<int>& frames) 
{ 
	for (int i = 0; i < frames.size(); i++) 
		if (frames[i] == key) 
			return true; 
	return false; 
} 

int predict(int pages[], vector<int>& frames, int pageSize, int index) 
{ 
	int frameIndex = -1, farthestPage = index; 
	for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = index; j < pageSize; j++) { 
			if (frames[i] == pages[j]) { 
				if (j > farthestPage) { 
					farthestPage = j; 
					frameIndex = i; 
				} 
				break; 
			} 
		} 

		if (j == pageSize) 
			return i; 
	} 

	if (frameIndex==-1){
        return 0;
    }else{
        return frameIndex;
    }
    
} 

void optimalPage() 
{ 

    cout << "\t\t\t\tWe will be using Optimal Page Replacement for Memory Management in Network OS"<<endl;
    int frameSize, pages[100],pageSize;

    cout << "Number of frames:";
    cin >> frameSize;

    cout << "Number of Pages:";
    cin >> pageSize;

    cout << "Pages Stream:";
    for (int i = 0; i < pageSize; i++)
    {
        cin >> pages[i];
    }
    
	vector<int> frames; 

	
	int hit = 0; 
	cout << "Frames are as follows:"<<endl;
    for (int i = 0; i < pageSize; i++) {
        cout << "Step"<<"["<<i<<"]:"<<endl;
        for (int i = 0; i < frames.size(); i++)
        {
            if (frames.size()==0)
            {
                cout << "Empty"<<endl;
                break;
            }
            
            cout <<" "<< frames[i]<<endl;
            cout << "---"<<endl;
        }

        

        if (searchIfPageAlreadyExistsInFrames(pages[i], frames)) { 
			hit++; 
			continue; 
		} 

		
		if (frames.size() < frameSize) 
			frames.push_back(pages[i]); 

		
		else { 
			int j = predict(pages, frames, pageSize, i + 1); 
			frames[j] = pages[i]; 
		} 
	} 
	cout << "No. of hits:" << hit << endl; 
	cout << "No. of misses:" << pageSize - hit << endl;
    cout << "Hit Percentage:" << (hit / pageSize) * 100 << "%"<<endl;
    cout << "Miss Percentage:" << ((pageSize - hit) / pageSize) * 100 << "%" << endl;
} 

 
int main() 
{
    int ch = 0;
    do
    {
        
        cout << "Choose one from the following:"<<endl;
        cout << "\n1.Memory Management";
        cout << "\n5.Exit";

        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            optimalPage();
            break;
        
        default:
            break;
        }

        if (ch<1 || ch>5)
        {
            cout << "Wrong Input!!" << endl;
            continue;
        }
        

    } while (ch!=5);
    
    
	return 0; 
} 
