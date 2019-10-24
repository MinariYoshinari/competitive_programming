int nxt = chips/(h+1), cnt = 0;
            flag = 1;
            vector<int> vh, vv;
            rep(r-1){
                if(waffle[i][c-1] == nxt){
                    nxt += chips/(h+1);
                    cnt++;
                    vh.push_back(i);
                }else if(waffle[i][c-1] > nxt){
                    flag = 0;
                    break;
                }
            }
            if(cnt != h) flag = 0;

            nxt = chips/((h+1)*(v+1));
            cnt = 0;
            if(flag) repp(j, c-1){
                if(waffle[r-1][j] == nxt){
                    nxt +=  chips/((h+1)*(v+1));
                    cnt++;
                    vv.push_back(j);
                }else if(waffle[r-1][j] > nxt){
                    flag = 0;
                    break;
                }
            }
            if(cnt != v) flag = 0;

            int part = chips/((h+1)*(v+1));
            reppp(hi, 1, (int)vh.size()){
                reppp(vi, 1, (int)vv.size()){
                    if(calc_total(vh[hi-1]+1, vv[vi-1]+1, vh[hi], vv[vi]) != part){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
            }