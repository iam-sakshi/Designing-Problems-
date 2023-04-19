class DNode{
    public :
    string page;
    DNode *prev ,*next;
    
    DNode(string url)
    {
        page=url;
        prev=NULL;
        next=NULL;
    }
};

class BrowserHistory {
public:
     DNode *Homepage;
     DNode *current;
        
    BrowserHistory(string homepage) {
        
       Homepage = new DNode(homepage);
        current = Homepage;
        
    }
    
    void visit(string url) {
        
        DNode *vst = new DNode(url);
        current->next=vst;
        vst->prev=current;
        current =vst;
        
    }
    
    string back(int steps) {
        
        while(steps>0 && current->prev !=NULL)
        {
            current =current->prev;
            steps--;
        }
        return current->page;
        
    }
    
    string forward(int steps) {
        
        while(steps>0 && current->next !=NULL)
        {
            current= current->next;
            steps--;
        }
        return current->page;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */