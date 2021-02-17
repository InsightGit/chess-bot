#ifndef CHESS_BOT_MINIMAX
#define CHESS_BOT_MINIMAX

#include "board.hpp"
#include <algorithm>
#include <limits>
namespace minimax{
    // maximizingplayer can be true or false, true being white, false being black.
    int minimax(chess::Board position, int depth, int alpha, int beta, bool maximizingplayer){
        if(depth == 0 || position.gameEndStatus() != chess::GameOutcome::InProgress){
            if(maximizingplayer && chess::GameOutcome::WhiteVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::max();
            }else if(!maximizingplayer && chess::GameOutcome::BlackVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::max();
            }else if(!maximizingplayer && chess::GameOutcome::WhiteVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::min();
            }else if(maximizingplayer && chess::GameOutcome::BlackVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::min();
            }
            return position.getStaticEval();
        }
        int eval;
        if(maximizingplayer){
            int maxEval = std::numeric_limits<int>::min();
            for(int x = 0; x < position.possible_states().size(); x ++){
                eval = minimax(position.possible_states()[x], depth - 1,alpha, beta, false);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if(beta <= alpha){
                    break;
                }
            }
            return maxEval; 
        }else{
            int minEval = std::numeric_limits<int>::min();
            for(int x = 0; x < position.possible_states().size(); x ++){
                eval = minimax(position.possible_states()[x], depth - 1,alpha, beta, false);
                minEval = std::min(minEval, eval);
                beta = std::min(beta,eval);
                if(beta <= alpha){
                    break;
                }
            }
            return minEval;
        }
    }
}

#endif CHESS_BOT_MINIMAX