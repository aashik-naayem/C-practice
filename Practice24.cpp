 
            else {
                low--;
                high++;
            }

            if (high < 0)
                return false;

            if (low < 0)
                low = 0;
        }

        return low == 0;
    }
};