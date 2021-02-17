#ifndef STESSTEST_HPP
#define STRESSTEST_HPP
#include "board.hpp"
namespace stresstest{
    // what this *should* do is return all of the possible board states at a given depth. 
    // This would help a LOT when your trying to test the engine half.
    int getAllMoves(chess::Board board, int depth){
        if(depth == 0 || board.game_end_status() != chess::GameOutcome::Tie){
            return 0;
        }
        int out = 0;
        for(chess::Board b : board.possible_states()){
            out += getAllMoves(b, depth-1);
        }
        return out;
    }
}

#endif STESSTEST_HPP