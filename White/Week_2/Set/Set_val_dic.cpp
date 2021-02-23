set<string> BuildMapValuesSet(const map<int, string>& m) 
{
    set<string> res;
    for (const auto& i : m)
    {
        res.insert(i.second);
    }
    return res;
}