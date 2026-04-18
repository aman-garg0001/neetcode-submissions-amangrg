class Solution {
    public boolean isPalindrome(String s) {
        final String sLowered = s.toLowerCase();
        final StringBuilder sWithoutSpecialChars = new StringBuilder();
        for (int i = 0; i < sLowered.length(); i++) {
            if ((sLowered.charAt(i) >= 'a' && sLowered.charAt(i) <= 'z')
                || (sLowered.charAt(i) >= '0' && sLowered.charAt(i) <= '9')) {
                sWithoutSpecialChars.append(sLowered.charAt(i));
            }
        }
        int len = sWithoutSpecialChars.length();
        for (int i = 0; i < len/2; i++) {
            if (sWithoutSpecialChars.charAt(i) != sWithoutSpecialChars.charAt(len - i - 1)) {
                return false;
            }
        }
        return true;
    }
}