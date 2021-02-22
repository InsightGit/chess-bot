//
// Created by bobby on 16/02/2021.
//

#include "piece_board.hpp"

chess::PieceBoard::PieceBoard() {
    for(int i = 0; 7 > i; ++i) {
        PieceType piece_type;

        if (i == 0 || i == 7) {
            piece_type = PieceType::Rook;
        } else if (i == 1 || i == 6) {
            piece_type = PieceType::Knight;
        } else if (i == 2 || i == 5) {
            piece_type = PieceType::Bishop;
        } else if (i == 3) {
            piece_type = PieceType::Queen;
        } else if(i == KING_ARRAY_PLACEMENT) {
            piece_type = PieceType::King;
        } else {
            // this should not happen...
            assert(false);
        }

        m_black_pieces[i] = Piece(false, piece_type, Vector2(i, 0));
        m_black_pieces[i + 7] = Piece(false, PieceType::Pawn, Vector2(i, 1));

        m_white_pieces[i] = Piece(true, piece_type, Vector2(i, 7));
        m_white_pieces[i + 7] = Piece(true, PieceType::Pawn, Vector2(i, 6));
    }
}

chess::PieceType
chess::PieceBoard::attack(chess::PieceType from_piece_type, chess::PieceType to_piece_type, int from_piece_id,
                          int to_piece_id) {
    return chess::PieceType::Rook;
}

chess::PieceType chess::PieceBoard::attack(chess::Vector2 from_pos, chess::Vector2 to_pos) {
    return chess::PieceType::Rook;
}

int chess::PieceBoard::get_static_eval() {
    return 0;
}

int chess::PieceBoard::get_fast_eval() {
    return 0;
}

chess::GameOutcome chess::PieceBoard::game_end_status() {
    bool black_checkmate = possible_states(false).empty();
    bool white_checkmate = possible_states(true).empty();

    if(black_checkmate && white_checkmate) {
        return chess::GameOutcome::Tie;
    } else if(black_checkmate) {
        return chess::GameOutcome::WhiteVictory;
    } else if(white_checkmate) {
        return chess::GameOutcome::BlackVictory;
    } else {
        return chess::GameOutcome::Tie;
    }
}

bool chess::PieceBoard::is_in_check(bool checking_white) {
    Piece *pieces_array;
    Vector2 target_position;

    assert(m_white_pieces[KING_ARRAY_PLACEMENT].get_type() == PieceType::King &&
           m_black_pieces[KING_ARRAY_PLACEMENT].get_type() == PieceType::King);

    if(checking_white) {
        pieces_array = m_white_pieces;
        target_position = m_white_pieces[KING_ARRAY_PLACEMENT].get_position();
    } else {
        assert(m_white_pieces[KING_ARRAY_PLACEMENT].get_type() == PieceType::King &&
               m_black_pieces[KING_ARRAY_PLACEMENT].get_type() == PieceType::King);

        pieces_array = m_black_pieces;
        target_position = m_black_pieces[KING_ARRAY_PLACEMENT].get_position();
    }

    for(int i = 0; 16 > i; ++i) {
        if(i != KING_ARRAY_PLACEMENT) {
            std::vector<Vector2> attack_positions = get_attack_positions(*(pieces_array + i));

            if(std::find(attack_positions.begin(), attack_positions.end(), target_position) != attack_positions.end()) {
                return true;
            }
        }
    }

    return false;
}

std::vector<chess::Board> chess::PieceBoard::possible_states(bool checking_white) {
    return std::vector<Board>();
}

void chess::PieceBoard::move(chess::Vector2 from_pos, chess::Vector2 to_pos) {

}

void chess::PieceBoard::move(chess::PieceType piece_type, chess::Vector2 to_pos, int piece_id) {

}

std::vector<chess::Vector2> chess::PieceBoard::get_attack_positions(Piece &piece) {
    Vector2 piece_position = piece.get_position();
    // for()
    return std::vector<Vector2>();
}
