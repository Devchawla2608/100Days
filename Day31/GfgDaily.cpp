string FirstNonRepeating(string A){
    // Code here
    queue<char> queue_chars;
    long repeataion_array[26]{0};
    string output;
    for(auto c : A)
    {
    repeataion_array[c-'a']++;
    queue_chars.push(c);
    while(!queue_chars.empty())
    {
    if(repeataion_array[queue_chars.front() - 'a'] == 1)
    {
       output.push_back(queue_chars.front()); 
       break;
    }
    else
    {
       queue_chars.pop();
    }
    } 
    if(queue_chars.empty())
    {
      output.push_back('#'); 
    }
    }
    
    return output;
}