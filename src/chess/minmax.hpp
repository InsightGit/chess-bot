#ifndef CHESS_BOT_MINIMAX
#define CHESS_BOT_MINIMAX

#include "board.hpp"
#include <algorithm>
#include <limits>
#include <vector>
namespace minimax{
    // maximizingplayer can be true or false, true being white, false being black.
    int minimax(chess::Board position, int depth, int alpha, int beta, bool maximizingplayer){
        if(depth == 0 || position.game_end_status() != chess::GameOutcome::InProgress){
            if(maximizingplayer && chess::GameOutcome::WhiteVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::max();
            }else if(!maximizingplayer && chess::GameOutcome::BlackVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::max();
            }else if(!maximizingplayer && chess::GameOutcome::WhiteVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::min();
            }else if(maximizingplayer && chess::GameOutcome::BlackVictory == position.gameEndStatus()){
                return std::numeric_limits<int>::min();
            }else if(chess::GameOutcome::Tie == position.game_end_status()){
                return 0;
            }
            return position.get_static_eval();
        }
        int eval;
        std::vector<chess::Board> orderedMoves = order_moves(position.possible_states());
        if(maximizingplayer){
            int maxEval = std::numeric_limits<int>::min();
            for(auto const& move : orderedMoves){
                eval = minimax(move, depth - 1,alpha, beta, false);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if(beta <= alpha){
                    break;
                }
            }
            return maxEval; 
        }else{
            int minEval = std::numeric_limits<int>::min();
            for(auto const& move : orderedMoves){
                eval = minimax(move, depth - 1,alpha, beta, false);
                minEval = std::min(minEval, eval);
                beta = std::min(beta,eval);
                if(beta <= alpha){
                    break;
                }
            }
            return minEval;
        }
    }

    std::vector<chess::Board> order_moves(std::vector<chess::Board> moves){
        auto sort_rule_lambda = [] (chess::Board const& b1, chess::Board const& b2) -> bool{
            return b1.get_fast_eval() > b2.get_fast_eval();
        };
        std::sort(moves.begin(), moves.end(), sort_rule_lambda);
        return moves;
    }
}

#endif CHESS_BOT_MINIMAX