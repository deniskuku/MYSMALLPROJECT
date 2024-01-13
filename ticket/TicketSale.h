#ifndef TICKET_SALE_H
#define TICKET_SALE_H

struct TicketSale
{
    double ticketPrice;
    int quantity;
    std::vector<std::string> seats;
};

#endif // TICKET_SALE_H