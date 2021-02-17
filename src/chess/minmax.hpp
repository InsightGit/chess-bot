#ifndef CHESS_BOT_MINIMAX
#define CHESS_BOT_MINIMAX

#include "board.hpp"
#include <algorithm>
#include <limits>
namespace minimax{
    
    int minimax(chess::Board position, int depth,bool maximizingplayer){
        if(depth == 0 || position.possible_states().size() == 0){
            return position.getStaticEval();
        }
        int eval;
        if(maximizingplayer){
            int maxEval = std::numeric_limits<int>::min();
            for(int x = 0; x < position.possible_states().size(); x ++){
                eval = minimax(position.possible_states()[x], depth - 1, false);
                maxEval = std::max(maxEval, eval);
            }
            return maxEval;
        }else{
            int minEval = std::numeric_limits<int>::min();
            for(int x = 0; x < position.possible_states().size(); x ++){
                eval = minimax(position.possible_states()[x], depth - 1, false);
                minEval = std::min(minEval, eval);
            }
            return minEval;
        }
    }
}

#endif CHESS_BOT_MINIMAX