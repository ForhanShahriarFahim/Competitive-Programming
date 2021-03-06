string makeString(vector<char> v)
{
    string s;
    for (int i = 0; i < v.size(); i++)
    {
        s.pb(v[i]);
    }
    cout << s << "\t";
    return s;
}
void solve()
{
    string myJaan = "fariha";
    vector<char> charVec;
    vector<string> AllNibbis;

    for (int i = 0; i < myJaan.size(); i++)
    {
        charVec.pb(myJaan[i]);
    }
    sort(All(charVec));

    // cout << charVec << endl;
    int jaan_count = 0;
    int ans = 0;

    do
    {
        string cur = makeString(charVec);
        AllNibbis.pb(cur);
        if (cur == "fariha")
        {
            ans = jaan_count;
        }
        else
            jaan_count++;

    } while (next_permutation(All(charVec)));

    cout << "Nibbi Count : " << AllNibbis.size() << endl;

    cout << "Where is my Jaan? " << ans << endl;
}