package com.pionix;

/**
 * Branch class represents a real life branch for a cargo company
 *
 */
public class Branch {
    private final String name;

    public Branch(String name) {
        this.name = name;
    }

    /**
     * Gets the branch name
     *
     * @return branch name
     */
    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return "Branch name: " + name;
    }
}
