
struct Page {
    string url;
    Page* next;
    Page* prev;
}


class BrowserHistory {
    public:
        BrowserHistory(string const& homepage){
            currPage = createPage(url);
        }

        void visit(string url){
            Page* newPage = createPage(url);
            // free memory on all next pages before moving pointers
            clearForwardHistory();
            currPage->next = newPage;
            newPage->prev = currPage;
            currPage = currPage->next;
        }

        string back(int steps){
            while(steps-- && currPage->prev != nullptr){
                currPage = currPage->prev;
            } 
            return currPage->url;
        }

        string forward(int steps){
            while(steps-- && currPage->next != nullptr){
                currPage = currPage->next;
            } 
            return currPage->url;
        }

    private:
        Page* currPage;

        Page* createPage(string const& url){
            Page* newPage = new Page;
            newPage->url = url;
            newPage->next = nullptr;
            newPage->prev = nullptr;
            return newPage; 
        }
        
        void clearForwardHistory(){
            if (currPage->next == nullptr) return;

            Page *tmp = currPage->next, *tmpNext;
            while(tmp->next != nullptr){
                tmpNext = tmp->next;
                delete tmp;
                tmp = tmpNext;
            }
            delete tmp;
        }
};

